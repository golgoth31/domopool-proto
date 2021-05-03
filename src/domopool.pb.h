/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.5 */

#ifndef PB_DOMOPOOL_DOMOPOOL_PB_H_INCLUDED
#define PB_DOMOPOOL_DOMOPOOL_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _domopool_Relay_states { 
    domopool_Relay_states_auto = 0, 
    domopool_Relay_states_start = 1, 
    domopool_Relay_states_stop = 2 
} domopool_Relay_states;

typedef enum _domopool_Relay_names { 
    domopool_Relay_names_filter = 0, 
    domopool_Relay_names_ch = 1, 
    domopool_Relay_names_ph = 2, 
    domopool_Relay_names_light = 3 
} domopool_Relay_names;

/* Struct definitions */
typedef struct _domopool_Ads115Alarms { 
    bool not_ready; 
    bool not_started; 
    bool not_connected; 
} domopool_Ads115Alarms;

typedef struct _domopool_AnalogSensor { 
    bool enabled; 
    float threshold; 
    uint32_t adc_pin; 
    uint32_t threshold_accuracy; 
    float vmin; 
    float vmax; 
    uint32_t precision_factor; 
    bool auto_cal; 
} domopool_AnalogSensor;

typedef struct _domopool_Global { 
    uint32_t lcd_backlight_duration; 
    uint32_t ack_duration; 
    double ack_tone; 
    bool serial_out; 
    bool display_startup; 
    bool force_light; 
    uint32_t wdt_duration; 
} domopool_Global;

typedef struct _domopool_Limits { 
    float wp_min; 
    float wp_max; 
    float ph_min; 
    float ph_max; 
    float ch_min; 
    float ch_max; 
    /* number of hour to wait when temp is above 15 to activate ch */
    uint32_t ch_wait_before_allow; 
    uint32_t ch_wait_before_deny; 
    /* temp threshold to activate ch */
    float ch_temp_threshold_high; 
    float ch_temp_threshold_low; 
    float wp_0_derive; 
    float tw_min; 
    float tw_max; 
    float tamb_min; 
} domopool_Limits;

typedef struct _domopool_Metrics { 
    float tamb; 
    float twater; 
    float saved_twater; 
    float ph; 
    float ch; 
    float wp; 
    float wp_volt; 
    uint32_t over_ch_t_high_duration; 
    uint32_t under_ch_t_low_duration; 
    uint32_t hour; 
    /* uint32 time = 10; */
    char time[30]; 
} domopool_Metrics;

typedef struct _domopool_Mqtt { 
    bool enabled; 
    char server[128]; 
} domopool_Mqtt;

typedef struct _domopool_MqttAlarms { 
    bool metrics; 
    bool states; 
    bool alarms; 
    bool temps; 
} domopool_MqttAlarms;

typedef struct _domopool_NTP { 
    uint32_t day_light; /* 3600 if daylight is observed or 0 if not */
    char server[128]; 
    uint32_t timezone; /* UTC offset in s: UTC+1=3600 */
} domopool_NTP;

typedef struct _domopool_Pump { 
    bool force_filter; 
    bool force_ph; 
    bool force_ch; 
    bool automatic; 
    bool recover; 
    bool force_check; 
    uint32_t force_duration; 
    uint32_t force_start_time; 
} domopool_Pump;

typedef struct _domopool_Relay { 
    domopool_Relay_states state; 
    domopool_Relay_names relay; 
    uint32_t duration; 
    uint32_t start_time; 
} domopool_Relay;

typedef struct _domopool_States { 
    bool startup; 
    bool filter_on; 
    bool ph_on; 
    bool ch_on; 
    bool automatic; 
    bool net_active; 
    bool ntp; 
    bool rtc; 
    bool light_on; 
    bool mqtt_connected; 
    bool recover; 
} domopool_States;

typedef struct _domopool_Temp { 
    bool enabled; 
    bool init; 
    pb_size_t addr_count;
    uint32_t addr[8]; 
} domopool_Temp;

typedef struct _domopool_Tests { 
    bool enabled; 
    float twater; 
    float tamb; 
    float ph; 
    float pressure; 
} domopool_Tests;

typedef struct _domopool_Versions { 
    char domopool[10]; 
    uint32_t platformio; 
    char esp_idf[128]; 
    char xtensa[10]; 
    char tft_espi[10]; 
    char dallastemp[10]; 
    char ads1115[10]; 
    char nanopb[12]; 
    char mqtt[10]; 
} domopool_Versions;

typedef struct _domopool_Alarms { 
    bool filter; 
    bool ph; 
    bool ch; 
    bool rtc; 
    bool wp_high; 
    bool wp_low; 
    bool wp_broken; 
    bool has_ads1115;
    domopool_Ads115Alarms ads1115; 
    bool tw_frost; 
    bool tw_high; 
    bool tamb_frost; 
    bool has_mqtt;
    domopool_MqttAlarms mqtt; 
    bool reboot; 
} domopool_Alarms;

typedef struct _domopool_Infos { 
    char compile[128]; 
    char board_name[128]; 
    bool has_versions;
    domopool_Versions versions; 
} domopool_Infos;

typedef struct _domopool_Network { 
    bool dhcp; 
    char ip[15]; 
    char netmask[15]; 
    char gateway[15]; 
    char dns[15]; 
    bool allow_post; 
    bool has_mqtt;
    domopool_Mqtt mqtt; 
    bool has_ntp;
    domopool_NTP ntp; 
} domopool_Network;

typedef struct _domopool_Sensors { 
    bool has_twin;
    domopool_Temp twin; 
    bool has_twout;
    domopool_Temp twout; 
    bool has_tamb;
    domopool_Temp tamb; 
    bool wait_for_conversion; 
    uint32_t temp_resolution; 
    uint32_t precision_factor; 
    bool has_ph;
    domopool_AnalogSensor ph; 
    bool has_ch;
    domopool_AnalogSensor ch; 
    bool has_wp;
    domopool_AnalogSensor wp; 
    uint32_t adc_mode; 
    uint32_t adc_datarate; 
    uint32_t adc_gain; 
} domopool_Sensors;

typedef struct _domopool_Config { 
    bool has_network;
    domopool_Network network; 
    bool has_sensors;
    domopool_Sensors sensors; 
    bool has_global;
    domopool_Global global; 
    bool has_pump;
    domopool_Pump pump; 
    bool has_metrics;
    domopool_Metrics metrics; 
    bool has_states;
    domopool_States states; 
    bool has_alarms;
    domopool_Alarms alarms; 
    bool has_tests;
    domopool_Tests tests; 
    bool has_infos;
    domopool_Infos infos; 
    bool has_limits;
    domopool_Limits limits; 
} domopool_Config;


/* Helper constants for enums */
#define _domopool_Relay_states_MIN domopool_Relay_states_auto
#define _domopool_Relay_states_MAX domopool_Relay_states_stop
#define _domopool_Relay_states_ARRAYSIZE ((domopool_Relay_states)(domopool_Relay_states_stop+1))

#define _domopool_Relay_names_MIN domopool_Relay_names_filter
#define _domopool_Relay_names_MAX domopool_Relay_names_light
#define _domopool_Relay_names_ARRAYSIZE ((domopool_Relay_names)(domopool_Relay_names_light+1))


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define domopool_NTP_init_default                {0, "", 0}
#define domopool_Mqtt_init_default               {0, ""}
#define domopool_Network_init_default            {0, "", "", "", "", 0, false, domopool_Mqtt_init_default, false, domopool_NTP_init_default}
#define domopool_Temp_init_default               {0, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0}}
#define domopool_Limits_init_default             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define domopool_AnalogSensor_init_default       {0, 0, 0, 0, 0, 0, 0, 0}
#define domopool_Sensors_init_default            {false, domopool_Temp_init_default, false, domopool_Temp_init_default, false, domopool_Temp_init_default, 0, 0, 0, false, domopool_AnalogSensor_init_default, false, domopool_AnalogSensor_init_default, false, domopool_AnalogSensor_init_default, 0, 0, 0}
#define domopool_Global_init_default             {0, 0, 0, 0, 0, 0, 0}
#define domopool_Pump_init_default               {0, 0, 0, 0, 0, 0, 0, 0}
#define domopool_Ads115Alarms_init_default       {0, 0, 0}
#define domopool_MqttAlarms_init_default         {0, 0, 0, 0}
#define domopool_Alarms_init_default             {0, 0, 0, 0, 0, 0, 0, false, domopool_Ads115Alarms_init_default, 0, 0, 0, false, domopool_MqttAlarms_init_default, 0}
#define domopool_Tests_init_default              {0, 0, 0, 0, 0}
#define domopool_Metrics_init_default            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""}
#define domopool_States_init_default             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define domopool_Versions_init_default           {"", 0, "", "", "", "", "", "", ""}
#define domopool_Infos_init_default              {"", "", false, domopool_Versions_init_default}
#define domopool_Config_init_default             {false, domopool_Network_init_default, false, domopool_Sensors_init_default, false, domopool_Global_init_default, false, domopool_Pump_init_default, false, domopool_Metrics_init_default, false, domopool_States_init_default, false, domopool_Alarms_init_default, false, domopool_Tests_init_default, false, domopool_Infos_init_default, false, domopool_Limits_init_default}
#define domopool_Relay_init_default              {_domopool_Relay_states_MIN, _domopool_Relay_names_MIN, 0, 0}
#define domopool_NTP_init_zero                   {0, "", 0}
#define domopool_Mqtt_init_zero                  {0, ""}
#define domopool_Network_init_zero               {0, "", "", "", "", 0, false, domopool_Mqtt_init_zero, false, domopool_NTP_init_zero}
#define domopool_Temp_init_zero                  {0, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0}}
#define domopool_Limits_init_zero                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define domopool_AnalogSensor_init_zero          {0, 0, 0, 0, 0, 0, 0, 0}
#define domopool_Sensors_init_zero               {false, domopool_Temp_init_zero, false, domopool_Temp_init_zero, false, domopool_Temp_init_zero, 0, 0, 0, false, domopool_AnalogSensor_init_zero, false, domopool_AnalogSensor_init_zero, false, domopool_AnalogSensor_init_zero, 0, 0, 0}
#define domopool_Global_init_zero                {0, 0, 0, 0, 0, 0, 0}
#define domopool_Pump_init_zero                  {0, 0, 0, 0, 0, 0, 0, 0}
#define domopool_Ads115Alarms_init_zero          {0, 0, 0}
#define domopool_MqttAlarms_init_zero            {0, 0, 0, 0}
#define domopool_Alarms_init_zero                {0, 0, 0, 0, 0, 0, 0, false, domopool_Ads115Alarms_init_zero, 0, 0, 0, false, domopool_MqttAlarms_init_zero, 0}
#define domopool_Tests_init_zero                 {0, 0, 0, 0, 0}
#define domopool_Metrics_init_zero               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ""}
#define domopool_States_init_zero                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define domopool_Versions_init_zero              {"", 0, "", "", "", "", "", "", ""}
#define domopool_Infos_init_zero                 {"", "", false, domopool_Versions_init_zero}
#define domopool_Config_init_zero                {false, domopool_Network_init_zero, false, domopool_Sensors_init_zero, false, domopool_Global_init_zero, false, domopool_Pump_init_zero, false, domopool_Metrics_init_zero, false, domopool_States_init_zero, false, domopool_Alarms_init_zero, false, domopool_Tests_init_zero, false, domopool_Infos_init_zero, false, domopool_Limits_init_zero}
#define domopool_Relay_init_zero                 {_domopool_Relay_states_MIN, _domopool_Relay_names_MIN, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define domopool_Ads115Alarms_not_ready_tag      1
#define domopool_Ads115Alarms_not_started_tag    2
#define domopool_Ads115Alarms_not_connected_tag  3
#define domopool_AnalogSensor_enabled_tag        1
#define domopool_AnalogSensor_threshold_tag      2
#define domopool_AnalogSensor_adc_pin_tag        3
#define domopool_AnalogSensor_threshold_accuracy_tag 4
#define domopool_AnalogSensor_vmin_tag           5
#define domopool_AnalogSensor_vmax_tag           6
#define domopool_AnalogSensor_precision_factor_tag 7
#define domopool_AnalogSensor_auto_cal_tag       8
#define domopool_Global_lcd_backlight_duration_tag 1
#define domopool_Global_ack_duration_tag         2
#define domopool_Global_ack_tone_tag             3
#define domopool_Global_serial_out_tag           4
#define domopool_Global_display_startup_tag      5
#define domopool_Global_force_light_tag          6
#define domopool_Global_wdt_duration_tag         7
#define domopool_Limits_wp_min_tag               1
#define domopool_Limits_wp_max_tag               2
#define domopool_Limits_ph_min_tag               3
#define domopool_Limits_ph_max_tag               4
#define domopool_Limits_ch_min_tag               5
#define domopool_Limits_ch_max_tag               6
#define domopool_Limits_ch_wait_before_allow_tag 7
#define domopool_Limits_ch_wait_before_deny_tag  8
#define domopool_Limits_ch_temp_threshold_high_tag 9
#define domopool_Limits_ch_temp_threshold_low_tag 10
#define domopool_Limits_wp_0_derive_tag          11
#define domopool_Limits_tw_min_tag               12
#define domopool_Limits_tw_max_tag               13
#define domopool_Limits_tamb_min_tag             14
#define domopool_Metrics_tamb_tag                1
#define domopool_Metrics_twater_tag              2
#define domopool_Metrics_saved_twater_tag        3
#define domopool_Metrics_ph_tag                  4
#define domopool_Metrics_ch_tag                  5
#define domopool_Metrics_wp_tag                  6
#define domopool_Metrics_wp_volt_tag             7
#define domopool_Metrics_over_ch_t_high_duration_tag 8
#define domopool_Metrics_under_ch_t_low_duration_tag 9
#define domopool_Metrics_hour_tag                10
#define domopool_Metrics_time_tag                11
#define domopool_Mqtt_enabled_tag                1
#define domopool_Mqtt_server_tag                 2
#define domopool_MqttAlarms_metrics_tag          1
#define domopool_MqttAlarms_states_tag           2
#define domopool_MqttAlarms_alarms_tag           3
#define domopool_MqttAlarms_temps_tag            4
#define domopool_NTP_day_light_tag               1
#define domopool_NTP_server_tag                  2
#define domopool_NTP_timezone_tag                3
#define domopool_Pump_force_filter_tag           1
#define domopool_Pump_force_ph_tag               2
#define domopool_Pump_force_ch_tag               3
#define domopool_Pump_automatic_tag              4
#define domopool_Pump_recover_tag                5
#define domopool_Pump_force_check_tag            6
#define domopool_Pump_force_duration_tag         7
#define domopool_Pump_force_start_time_tag       8
#define domopool_Relay_state_tag                 1
#define domopool_Relay_relay_tag                 2
#define domopool_Relay_duration_tag              3
#define domopool_Relay_start_time_tag            4
#define domopool_States_startup_tag              1
#define domopool_States_filter_on_tag            2
#define domopool_States_ph_on_tag                3
#define domopool_States_ch_on_tag                4
#define domopool_States_automatic_tag            5
#define domopool_States_net_active_tag           6
#define domopool_States_ntp_tag                  7
#define domopool_States_rtc_tag                  8
#define domopool_States_light_on_tag             9
#define domopool_States_mqtt_connected_tag       10
#define domopool_States_recover_tag              11
#define domopool_Temp_enabled_tag                1
#define domopool_Temp_init_tag                   2
#define domopool_Temp_addr_tag                   8
#define domopool_Tests_enabled_tag               1
#define domopool_Tests_twater_tag                2
#define domopool_Tests_tamb_tag                  3
#define domopool_Tests_ph_tag                    4
#define domopool_Tests_pressure_tag              5
#define domopool_Versions_domopool_tag           1
#define domopool_Versions_platformio_tag         2
#define domopool_Versions_esp_idf_tag            3
#define domopool_Versions_xtensa_tag             4
#define domopool_Versions_tft_espi_tag           6
#define domopool_Versions_dallastemp_tag         7
#define domopool_Versions_ads1115_tag            8
#define domopool_Versions_nanopb_tag             9
#define domopool_Versions_mqtt_tag               10
#define domopool_Alarms_filter_tag               1
#define domopool_Alarms_ph_tag                   2
#define domopool_Alarms_ch_tag                   3
#define domopool_Alarms_rtc_tag                  5
#define domopool_Alarms_wp_high_tag              6
#define domopool_Alarms_wp_low_tag               7
#define domopool_Alarms_wp_broken_tag            8
#define domopool_Alarms_ads1115_tag              9
#define domopool_Alarms_tw_frost_tag             10
#define domopool_Alarms_tw_high_tag              11
#define domopool_Alarms_tamb_frost_tag           12
#define domopool_Alarms_mqtt_tag                 13
#define domopool_Alarms_reboot_tag               14
#define domopool_Infos_compile_tag               1
#define domopool_Infos_board_name_tag            2
#define domopool_Infos_versions_tag              3
#define domopool_Network_dhcp_tag                1
#define domopool_Network_ip_tag                  2
#define domopool_Network_netmask_tag             3
#define domopool_Network_gateway_tag             4
#define domopool_Network_dns_tag                 5
#define domopool_Network_allow_post_tag          6
#define domopool_Network_mqtt_tag                7
#define domopool_Network_ntp_tag                 8
#define domopool_Sensors_twin_tag                1
#define domopool_Sensors_twout_tag               2
#define domopool_Sensors_tamb_tag                3
#define domopool_Sensors_wait_for_conversion_tag 4
#define domopool_Sensors_temp_resolution_tag     5
#define domopool_Sensors_precision_factor_tag    6
#define domopool_Sensors_ph_tag                  7
#define domopool_Sensors_ch_tag                  8
#define domopool_Sensors_wp_tag                  9
#define domopool_Sensors_adc_mode_tag            10
#define domopool_Sensors_adc_datarate_tag        11
#define domopool_Sensors_adc_gain_tag            12
#define domopool_Config_network_tag              1
#define domopool_Config_sensors_tag              2
#define domopool_Config_global_tag               3
#define domopool_Config_pump_tag                 5
#define domopool_Config_metrics_tag              6
#define domopool_Config_states_tag               7
#define domopool_Config_alarms_tag               8
#define domopool_Config_tests_tag                9
#define domopool_Config_infos_tag                10
#define domopool_Config_limits_tag               11

/* Struct field encoding specification for nanopb */
#define domopool_NTP_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   day_light,         1) \
X(a, STATIC,   SINGULAR, STRING,   server,            2) \
X(a, STATIC,   SINGULAR, UINT32,   timezone,          3)
#define domopool_NTP_CALLBACK NULL
#define domopool_NTP_DEFAULT NULL

#define domopool_Mqtt_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     enabled,           1) \
X(a, STATIC,   SINGULAR, STRING,   server,            2)
#define domopool_Mqtt_CALLBACK NULL
#define domopool_Mqtt_DEFAULT NULL

#define domopool_Network_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     dhcp,              1) \
X(a, STATIC,   SINGULAR, STRING,   ip,                2) \
X(a, STATIC,   SINGULAR, STRING,   netmask,           3) \
X(a, STATIC,   SINGULAR, STRING,   gateway,           4) \
X(a, STATIC,   SINGULAR, STRING,   dns,               5) \
X(a, STATIC,   SINGULAR, BOOL,     allow_post,        6) \
X(a, STATIC,   OPTIONAL, MESSAGE,  mqtt,              7) \
X(a, STATIC,   OPTIONAL, MESSAGE,  ntp,               8)
#define domopool_Network_CALLBACK NULL
#define domopool_Network_DEFAULT NULL
#define domopool_Network_mqtt_MSGTYPE domopool_Mqtt
#define domopool_Network_ntp_MSGTYPE domopool_NTP

#define domopool_Temp_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     enabled,           1) \
X(a, STATIC,   SINGULAR, BOOL,     init,              2) \
X(a, STATIC,   REPEATED, UINT32,   addr,              8)
#define domopool_Temp_CALLBACK NULL
#define domopool_Temp_DEFAULT NULL

#define domopool_Limits_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, FLOAT,    wp_min,            1) \
X(a, STATIC,   SINGULAR, FLOAT,    wp_max,            2) \
X(a, STATIC,   SINGULAR, FLOAT,    ph_min,            3) \
X(a, STATIC,   SINGULAR, FLOAT,    ph_max,            4) \
X(a, STATIC,   SINGULAR, FLOAT,    ch_min,            5) \
X(a, STATIC,   SINGULAR, FLOAT,    ch_max,            6) \
X(a, STATIC,   SINGULAR, UINT32,   ch_wait_before_allow,   7) \
X(a, STATIC,   SINGULAR, UINT32,   ch_wait_before_deny,   8) \
X(a, STATIC,   SINGULAR, FLOAT,    ch_temp_threshold_high,   9) \
X(a, STATIC,   SINGULAR, FLOAT,    ch_temp_threshold_low,  10) \
X(a, STATIC,   SINGULAR, FLOAT,    wp_0_derive,      11) \
X(a, STATIC,   SINGULAR, FLOAT,    tw_min,           12) \
X(a, STATIC,   SINGULAR, FLOAT,    tw_max,           13) \
X(a, STATIC,   SINGULAR, FLOAT,    tamb_min,         14)
#define domopool_Limits_CALLBACK NULL
#define domopool_Limits_DEFAULT NULL

#define domopool_AnalogSensor_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     enabled,           1) \
X(a, STATIC,   SINGULAR, FLOAT,    threshold,         2) \
X(a, STATIC,   SINGULAR, UINT32,   adc_pin,           3) \
X(a, STATIC,   SINGULAR, UINT32,   threshold_accuracy,   4) \
X(a, STATIC,   SINGULAR, FLOAT,    vmin,              5) \
X(a, STATIC,   SINGULAR, FLOAT,    vmax,              6) \
X(a, STATIC,   SINGULAR, UINT32,   precision_factor,   7) \
X(a, STATIC,   SINGULAR, BOOL,     auto_cal,          8)
#define domopool_AnalogSensor_CALLBACK NULL
#define domopool_AnalogSensor_DEFAULT NULL

#define domopool_Sensors_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  twin,              1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  twout,             2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  tamb,              3) \
X(a, STATIC,   SINGULAR, BOOL,     wait_for_conversion,   4) \
X(a, STATIC,   SINGULAR, UINT32,   temp_resolution,   5) \
X(a, STATIC,   SINGULAR, UINT32,   precision_factor,   6) \
X(a, STATIC,   OPTIONAL, MESSAGE,  ph,                7) \
X(a, STATIC,   OPTIONAL, MESSAGE,  ch,                8) \
X(a, STATIC,   OPTIONAL, MESSAGE,  wp,                9) \
X(a, STATIC,   SINGULAR, UINT32,   adc_mode,         10) \
X(a, STATIC,   SINGULAR, UINT32,   adc_datarate,     11) \
X(a, STATIC,   SINGULAR, UINT32,   adc_gain,         12)
#define domopool_Sensors_CALLBACK NULL
#define domopool_Sensors_DEFAULT NULL
#define domopool_Sensors_twin_MSGTYPE domopool_Temp
#define domopool_Sensors_twout_MSGTYPE domopool_Temp
#define domopool_Sensors_tamb_MSGTYPE domopool_Temp
#define domopool_Sensors_ph_MSGTYPE domopool_AnalogSensor
#define domopool_Sensors_ch_MSGTYPE domopool_AnalogSensor
#define domopool_Sensors_wp_MSGTYPE domopool_AnalogSensor

#define domopool_Global_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   lcd_backlight_duration,   1) \
X(a, STATIC,   SINGULAR, UINT32,   ack_duration,      2) \
X(a, STATIC,   SINGULAR, DOUBLE,   ack_tone,          3) \
X(a, STATIC,   SINGULAR, BOOL,     serial_out,        4) \
X(a, STATIC,   SINGULAR, BOOL,     display_startup,   5) \
X(a, STATIC,   SINGULAR, BOOL,     force_light,       6) \
X(a, STATIC,   SINGULAR, UINT32,   wdt_duration,      7)
#define domopool_Global_CALLBACK NULL
#define domopool_Global_DEFAULT NULL

#define domopool_Pump_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     force_filter,      1) \
X(a, STATIC,   SINGULAR, BOOL,     force_ph,          2) \
X(a, STATIC,   SINGULAR, BOOL,     force_ch,          3) \
X(a, STATIC,   SINGULAR, BOOL,     automatic,         4) \
X(a, STATIC,   SINGULAR, BOOL,     recover,           5) \
X(a, STATIC,   SINGULAR, BOOL,     force_check,       6) \
X(a, STATIC,   SINGULAR, UINT32,   force_duration,    7) \
X(a, STATIC,   SINGULAR, UINT32,   force_start_time,   8)
#define domopool_Pump_CALLBACK NULL
#define domopool_Pump_DEFAULT NULL

#define domopool_Ads115Alarms_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     not_ready,         1) \
X(a, STATIC,   SINGULAR, BOOL,     not_started,       2) \
X(a, STATIC,   SINGULAR, BOOL,     not_connected,     3)
#define domopool_Ads115Alarms_CALLBACK NULL
#define domopool_Ads115Alarms_DEFAULT NULL

#define domopool_MqttAlarms_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     metrics,           1) \
X(a, STATIC,   SINGULAR, BOOL,     states,            2) \
X(a, STATIC,   SINGULAR, BOOL,     alarms,            3) \
X(a, STATIC,   SINGULAR, BOOL,     temps,             4)
#define domopool_MqttAlarms_CALLBACK NULL
#define domopool_MqttAlarms_DEFAULT NULL

#define domopool_Alarms_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     filter,            1) \
X(a, STATIC,   SINGULAR, BOOL,     ph,                2) \
X(a, STATIC,   SINGULAR, BOOL,     ch,                3) \
X(a, STATIC,   SINGULAR, BOOL,     rtc,               5) \
X(a, STATIC,   SINGULAR, BOOL,     wp_high,           6) \
X(a, STATIC,   SINGULAR, BOOL,     wp_low,            7) \
X(a, STATIC,   SINGULAR, BOOL,     wp_broken,         8) \
X(a, STATIC,   OPTIONAL, MESSAGE,  ads1115,           9) \
X(a, STATIC,   SINGULAR, BOOL,     tw_frost,         10) \
X(a, STATIC,   SINGULAR, BOOL,     tw_high,          11) \
X(a, STATIC,   SINGULAR, BOOL,     tamb_frost,       12) \
X(a, STATIC,   OPTIONAL, MESSAGE,  mqtt,             13) \
X(a, STATIC,   SINGULAR, BOOL,     reboot,           14)
#define domopool_Alarms_CALLBACK NULL
#define domopool_Alarms_DEFAULT NULL
#define domopool_Alarms_ads1115_MSGTYPE domopool_Ads115Alarms
#define domopool_Alarms_mqtt_MSGTYPE domopool_MqttAlarms

#define domopool_Tests_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     enabled,           1) \
X(a, STATIC,   SINGULAR, FLOAT,    twater,            2) \
X(a, STATIC,   SINGULAR, FLOAT,    tamb,              3) \
X(a, STATIC,   SINGULAR, FLOAT,    ph,                4) \
X(a, STATIC,   SINGULAR, FLOAT,    pressure,          5)
#define domopool_Tests_CALLBACK NULL
#define domopool_Tests_DEFAULT NULL

#define domopool_Metrics_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, FLOAT,    tamb,              1) \
X(a, STATIC,   SINGULAR, FLOAT,    twater,            2) \
X(a, STATIC,   SINGULAR, FLOAT,    saved_twater,      3) \
X(a, STATIC,   SINGULAR, FLOAT,    ph,                4) \
X(a, STATIC,   SINGULAR, FLOAT,    ch,                5) \
X(a, STATIC,   SINGULAR, FLOAT,    wp,                6) \
X(a, STATIC,   SINGULAR, FLOAT,    wp_volt,           7) \
X(a, STATIC,   SINGULAR, UINT32,   over_ch_t_high_duration,   8) \
X(a, STATIC,   SINGULAR, UINT32,   under_ch_t_low_duration,   9) \
X(a, STATIC,   SINGULAR, UINT32,   hour,             10) \
X(a, STATIC,   SINGULAR, STRING,   time,             11)
#define domopool_Metrics_CALLBACK NULL
#define domopool_Metrics_DEFAULT NULL

#define domopool_States_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     startup,           1) \
X(a, STATIC,   SINGULAR, BOOL,     filter_on,         2) \
X(a, STATIC,   SINGULAR, BOOL,     ph_on,             3) \
X(a, STATIC,   SINGULAR, BOOL,     ch_on,             4) \
X(a, STATIC,   SINGULAR, BOOL,     automatic,         5) \
X(a, STATIC,   SINGULAR, BOOL,     net_active,        6) \
X(a, STATIC,   SINGULAR, BOOL,     ntp,               7) \
X(a, STATIC,   SINGULAR, BOOL,     rtc,               8) \
X(a, STATIC,   SINGULAR, BOOL,     light_on,          9) \
X(a, STATIC,   SINGULAR, BOOL,     mqtt_connected,   10) \
X(a, STATIC,   SINGULAR, BOOL,     recover,          11)
#define domopool_States_CALLBACK NULL
#define domopool_States_DEFAULT NULL

#define domopool_Versions_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, STRING,   domopool,          1) \
X(a, STATIC,   SINGULAR, UINT32,   platformio,        2) \
X(a, STATIC,   SINGULAR, STRING,   esp_idf,           3) \
X(a, STATIC,   SINGULAR, STRING,   xtensa,            4) \
X(a, STATIC,   SINGULAR, STRING,   tft_espi,          6) \
X(a, STATIC,   SINGULAR, STRING,   dallastemp,        7) \
X(a, STATIC,   SINGULAR, STRING,   ads1115,           8) \
X(a, STATIC,   SINGULAR, STRING,   nanopb,            9) \
X(a, STATIC,   SINGULAR, STRING,   mqtt,             10)
#define domopool_Versions_CALLBACK NULL
#define domopool_Versions_DEFAULT NULL

#define domopool_Infos_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, STRING,   compile,           1) \
X(a, STATIC,   SINGULAR, STRING,   board_name,        2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  versions,          3)
#define domopool_Infos_CALLBACK NULL
#define domopool_Infos_DEFAULT NULL
#define domopool_Infos_versions_MSGTYPE domopool_Versions

#define domopool_Config_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  network,           1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  sensors,           2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  global,            3) \
X(a, STATIC,   OPTIONAL, MESSAGE,  pump,              5) \
X(a, STATIC,   OPTIONAL, MESSAGE,  metrics,           6) \
X(a, STATIC,   OPTIONAL, MESSAGE,  states,            7) \
X(a, STATIC,   OPTIONAL, MESSAGE,  alarms,            8) \
X(a, STATIC,   OPTIONAL, MESSAGE,  tests,             9) \
X(a, STATIC,   OPTIONAL, MESSAGE,  infos,            10) \
X(a, STATIC,   OPTIONAL, MESSAGE,  limits,           11)
#define domopool_Config_CALLBACK NULL
#define domopool_Config_DEFAULT NULL
#define domopool_Config_network_MSGTYPE domopool_Network
#define domopool_Config_sensors_MSGTYPE domopool_Sensors
#define domopool_Config_global_MSGTYPE domopool_Global
#define domopool_Config_pump_MSGTYPE domopool_Pump
#define domopool_Config_metrics_MSGTYPE domopool_Metrics
#define domopool_Config_states_MSGTYPE domopool_States
#define domopool_Config_alarms_MSGTYPE domopool_Alarms
#define domopool_Config_tests_MSGTYPE domopool_Tests
#define domopool_Config_infos_MSGTYPE domopool_Infos
#define domopool_Config_limits_MSGTYPE domopool_Limits

#define domopool_Relay_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    state,             1) \
X(a, STATIC,   SINGULAR, UENUM,    relay,             2) \
X(a, STATIC,   SINGULAR, UINT32,   duration,          3) \
X(a, STATIC,   SINGULAR, UINT32,   start_time,        4)
#define domopool_Relay_CALLBACK NULL
#define domopool_Relay_DEFAULT NULL

extern const pb_msgdesc_t domopool_NTP_msg;
extern const pb_msgdesc_t domopool_Mqtt_msg;
extern const pb_msgdesc_t domopool_Network_msg;
extern const pb_msgdesc_t domopool_Temp_msg;
extern const pb_msgdesc_t domopool_Limits_msg;
extern const pb_msgdesc_t domopool_AnalogSensor_msg;
extern const pb_msgdesc_t domopool_Sensors_msg;
extern const pb_msgdesc_t domopool_Global_msg;
extern const pb_msgdesc_t domopool_Pump_msg;
extern const pb_msgdesc_t domopool_Ads115Alarms_msg;
extern const pb_msgdesc_t domopool_MqttAlarms_msg;
extern const pb_msgdesc_t domopool_Alarms_msg;
extern const pb_msgdesc_t domopool_Tests_msg;
extern const pb_msgdesc_t domopool_Metrics_msg;
extern const pb_msgdesc_t domopool_States_msg;
extern const pb_msgdesc_t domopool_Versions_msg;
extern const pb_msgdesc_t domopool_Infos_msg;
extern const pb_msgdesc_t domopool_Config_msg;
extern const pb_msgdesc_t domopool_Relay_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define domopool_NTP_fields &domopool_NTP_msg
#define domopool_Mqtt_fields &domopool_Mqtt_msg
#define domopool_Network_fields &domopool_Network_msg
#define domopool_Temp_fields &domopool_Temp_msg
#define domopool_Limits_fields &domopool_Limits_msg
#define domopool_AnalogSensor_fields &domopool_AnalogSensor_msg
#define domopool_Sensors_fields &domopool_Sensors_msg
#define domopool_Global_fields &domopool_Global_msg
#define domopool_Pump_fields &domopool_Pump_msg
#define domopool_Ads115Alarms_fields &domopool_Ads115Alarms_msg
#define domopool_MqttAlarms_fields &domopool_MqttAlarms_msg
#define domopool_Alarms_fields &domopool_Alarms_msg
#define domopool_Tests_fields &domopool_Tests_msg
#define domopool_Metrics_fields &domopool_Metrics_msg
#define domopool_States_fields &domopool_States_msg
#define domopool_Versions_fields &domopool_Versions_msg
#define domopool_Infos_fields &domopool_Infos_msg
#define domopool_Config_fields &domopool_Config_msg
#define domopool_Relay_fields &domopool_Relay_msg

/* Maximum encoded size of messages (where known) */
#define domopool_Ads115Alarms_size               6
#define domopool_Alarms_size                     40
#define domopool_AnalogSensor_size               37
#define domopool_Config_size                     1457
#define domopool_Global_size                     33
#define domopool_Infos_size                      478
#define domopool_Limits_size                     72
#define domopool_Metrics_size                    84
#define domopool_MqttAlarms_size                 8
#define domopool_Mqtt_size                       132
#define domopool_NTP_size                        142
#define domopool_Network_size                    348
#define domopool_Pump_size                       24
#define domopool_Relay_size                      16
#define domopool_Sensors_size                    311
#define domopool_States_size                     22
#define domopool_Temp_size                       52
#define domopool_Tests_size                      22
#define domopool_Versions_size                   215

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
