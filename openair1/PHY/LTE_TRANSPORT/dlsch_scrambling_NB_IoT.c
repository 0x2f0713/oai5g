/*******************************************************************************

 *******************************************************************************/
/*! \file PHY/LTE_TRANSPORT/dlsch_scrambling_NB_IoT.c
* \brief Routines for the scrambling procedure of the NPDSCH physical channel for NB_IoT,	 TS 36-211, V13.4.0 2017-02
* \author M. KANJ
* \date 2017
* \version 0.0
* \company bcom
* \email: matthieu.kanj@b-com.com
* \note
* \warning
*/

//#define DEBUG_SCRAMBLING 1

//#include "PHY/defs.h"
//#include "PHY/defs_NB_IoT.h"
//#include "PHY/CODING/extern.h"
//#include "PHY/CODING/lte_interleaver_inline.h"
//#include "defs.h"
//#include "extern_NB_IoT.h"
//#include "PHY/extern_NB_IoT.h"
//#include "UTIL/LOG/vcd_signal_dumper.h"

#include "PHY/LTE_TRANSPORT/defs_NB_IoT.h"
#include "PHY/impl_defs_lte_NB_IoT.h"
#include "PHY/impl_defs_lte.h"
#include "PHY/LTE_REFSIG/defs_NB_IoT.h"

void dlsch_sib1_scrambling_NB_IoT(LTE_DL_FRAME_PARMS     *frame_parms,
							                    NB_IoT_eNB_NDLSCH_t    *dlsch,
							                    int                    tot_bits,        				// total number of bits to transmit
							                    uint8_t                Nf,   						// Nf is the frame number (0..9)
							                    uint8_t                Ns)							  // slot number (0..19)
{
  int         i,j,k=0;
  uint32_t    x1,x2, s=0;
  uint8_t     *e = dlsch->harq_process_sib1.e; 															//uint8_t *e=dlsch->harq_processes[dlsch->current_harq_pid]->e;

  x2 = (dlsch->harq_process_sib1.si_rnti<<15) + (frame_parms->Nid_cell + 1) * ( (Nf % 61) + 1 ) ;

  // for NPDSCH not carriying SIBs
  //x2 = (dlsch->harq_process_sib1.rnti<<14) + ((Nf%2)<<13) + ((Ns>>1)<<9) + frame_parms->Nid_cell;   //this is c_init in 36.211 Sec 10.2.3.1
  
  s = lte_gold_generic_NB_IoT(&x1, &x2, 1);

  for (i=0; i<(1+(tot_bits>>5)); i++) {

    for (j=0; j<32; j++,k++) {

      dlsch->harq_process_sib1.s_e[k] = (e[k]&1) ^ ((s>>j)&1);

    }
    s = lte_gold_generic_NB_IoT(&x1, &x2, 0);
  }

}
