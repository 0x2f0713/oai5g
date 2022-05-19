/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-KPM-IEs"
 * 	found in "/home/rshacham/e2sm-kpm-v01.02.asn"
 * 	`asn1c -fcompound-names`
 */

#include "CU-UP-Usage-Report-CellResourceReportItem.h"

static int
memb_ueResourceReportList_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 32)) {
		/* Perform validation of the inner elements */
		return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_type_ueResourceReportList_constr_3 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..32)) */};
static asn_per_constraints_t asn_PER_type_ueResourceReportList_constr_3 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 5,  5,  1,  32 }	/* (SIZE(1..32)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_ueResourceReportList_constr_3 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..32)) */};
static asn_per_constraints_t asn_PER_memb_ueResourceReportList_constr_3 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 5,  5,  1,  32 }	/* (SIZE(1..32)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_ueResourceReportList_3[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_CU_UP_Usage_Report_UeResourceReportItem,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_ueResourceReportList_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_ueResourceReportList_specs_3 = {
	sizeof(struct CU_UP_Usage_Report_CellResourceReportItem__ueResourceReportList),
	offsetof(struct CU_UP_Usage_Report_CellResourceReportItem__ueResourceReportList, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ueResourceReportList_3 = {
	"ueResourceReportList",
	"ueResourceReportList",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_ueResourceReportList_tags_3,
	sizeof(asn_DEF_ueResourceReportList_tags_3)
		/sizeof(asn_DEF_ueResourceReportList_tags_3[0]) - 1, /* 1 */
	asn_DEF_ueResourceReportList_tags_3,	/* Same as above */
	sizeof(asn_DEF_ueResourceReportList_tags_3)
		/sizeof(asn_DEF_ueResourceReportList_tags_3[0]), /* 2 */
	{ &asn_OER_type_ueResourceReportList_constr_3, &asn_PER_type_ueResourceReportList_constr_3, SEQUENCE_OF_constraint },
	asn_MBR_ueResourceReportList_3,
	1,	/* Single element */
	&asn_SPC_ueResourceReportList_specs_3	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_CU_UP_Usage_Report_CellResourceReportItem_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CU_UP_Usage_Report_CellResourceReportItem, nRCGI),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NRCGI,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nRCGI"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CU_UP_Usage_Report_CellResourceReportItem, ueResourceReportList),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_ueResourceReportList_3,
		0,
		{ &asn_OER_memb_ueResourceReportList_constr_3, &asn_PER_memb_ueResourceReportList_constr_3,  memb_ueResourceReportList_constraint_1 },
		0, 0, /* No default value */
		"ueResourceReportList"
		},
};
static const ber_tlv_tag_t asn_DEF_CU_UP_Usage_Report_CellResourceReportItem_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_CU_UP_Usage_Report_CellResourceReportItem_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* nRCGI */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* ueResourceReportList */
};
asn_SEQUENCE_specifics_t asn_SPC_CU_UP_Usage_Report_CellResourceReportItem_specs_1 = {
	sizeof(struct CU_UP_Usage_Report_CellResourceReportItem),
	offsetof(struct CU_UP_Usage_Report_CellResourceReportItem, _asn_ctx),
	asn_MAP_CU_UP_Usage_Report_CellResourceReportItem_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_CU_UP_Usage_Report_CellResourceReportItem = {
	"CU-UP-Usage-Report-CellResourceReportItem",
	"CU-UP-Usage-Report-CellResourceReportItem",
	&asn_OP_SEQUENCE,
	asn_DEF_CU_UP_Usage_Report_CellResourceReportItem_tags_1,
	sizeof(asn_DEF_CU_UP_Usage_Report_CellResourceReportItem_tags_1)
		/sizeof(asn_DEF_CU_UP_Usage_Report_CellResourceReportItem_tags_1[0]), /* 1 */
	asn_DEF_CU_UP_Usage_Report_CellResourceReportItem_tags_1,	/* Same as above */
	sizeof(asn_DEF_CU_UP_Usage_Report_CellResourceReportItem_tags_1)
		/sizeof(asn_DEF_CU_UP_Usage_Report_CellResourceReportItem_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_CU_UP_Usage_Report_CellResourceReportItem_1,
	2,	/* Elements count */
	&asn_SPC_CU_UP_Usage_Report_CellResourceReportItem_specs_1	/* Additional specs */
};

