#ifndef S6A_MESSAGES_TYPES_H_
#define S6A_MESSAGES_TYPES_H_

#define AUTS_LENGTH 14

typedef struct s6a_update_location_req_s {
#define SKIP_SUBSCRIBER_DATA (0x1)
    unsigned skip_subscriber_data:1;
#define INITIAL_ATTACH       (0x1)
    unsigned initial_attach:1;

    char       imsi[IMSI_DIGITS_MAX + 1]; // username
    uint8_t    imsi_length;               // username

    plmn_t     visited_plmn;              // visited plmn id
    rat_type_t rat_type;                  // rat type

    // missing                           // origin host
    // missing                           // origin realm

    // missing                           // destination host
    // missing                           // destination realm
} s6a_update_location_req_t;

typedef struct s6a_update_location_ans_s {
    s6a_result_t        result;              // Result of the update location request procedure
    subscription_data_t subscription_data;   // subscriber status,
                                             // Maximum Requested Bandwidth Uplink, downlink
                                             // access restriction data
                                             // msisdn
    apn_config_profile_t  apn_config_profile;// APN configuration profile

    network_access_mode_t access_mode;
    rau_tau_timer_t       rau_tau_timer;
    char    imsi[IMSI_DIGITS_MAX + 1];
    uint8_t imsi_length;


} s6a_update_location_ans_t;

typedef struct s6a_auth_info_req_s {
    char    imsi[IMSI_DIGITS_MAX + 1];
    uint8_t imsi_length;
    plmn_t  visited_plmn;
    /* Number of vectors to retrieve from HSS, should be equal to one */
    uint8_t nb_of_vectors;

    /* Bit to indicate that USIM has requested a re-synchronization of SQN */
    unsigned re_synchronization:1;
    /* AUTS to provide to AUC.
     * Only present and interpreted if re_synchronization == 1.
     */
    uint8_t auts[AUTS_LENGTH];
} s6a_auth_info_req_t;

typedef struct s6a_auth_info_ans_s {
    char       imsi[IMSI_DIGITS_MAX + 1];
    uint8_t    imsi_length;

    /* Result of the authentication information procedure */
    s6a_result_t result;
    /* Authentication info containing the vector(s) */
    authentication_info_t auth_info;
} s6a_auth_info_ans_t;

#endif /* S6A_MESSAGES_TYPES_H_ */
