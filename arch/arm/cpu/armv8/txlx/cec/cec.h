/*
 * arch/arm/cpu/armv8/txlx/cec/cec.h
 *
 * Copyright (C) 2012 AMLOGIC, INC. All Rights Reserved.
 * Author: hongmin hua <hongmin hua@amlogic.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the smems of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 */
#ifndef _CEC_H
#define _CEC_H

#ifndef CONFIG_CEC_OSD_NAME
#define CONFIG_CEC_OSD_NAME "AML_TV"
#endif

/*CEC UI MASK*/
#define CEC_FUNC_MASK                        0
#define ONE_TOUCH_PLAY_MASK                  1
#define ONE_TOUCH_STANDBY_MASK               2
#define AUTO_POWER_ON_MASK                   3

#define MAX_MSG 16
#define CEC_PLAYBACK_DEVICE_TYPE 4
#define CEC_BROADCAST_ADDR 0xf
#define CEC_VERSION_14A 5

enum _cec_log_dev_addr_e {
	CEC_TV_ADDR = 0x00,
	CEC_RECORDING_DEVICE_1_ADDR,
	CEC_RECORDING_DEVICE_2_ADDR,
	CEC_TUNER_1_ADDR,
	CEC_PLAYBACK_DEVICE_1_ADDR,
	CEC_AUDIO_SYSTEM_ADDR,
	CEC_TUNER_2_ADDR,
	CEC_TUNER_3_ADDR,
	CEC_PLAYBACK_DEVICE_2_ADDR,
	CEC_RECORDING_DEVICE_3_ADDR,
	CEC_TUNER_4_ADDR,
	CEC_PLAYBACK_DEVICE_3_ADDR,
	CEC_RESERVED_1_ADDR,
	CEC_RESERVED_2_ADDR,
	CEC_FREE_USE_ADDR,
	CEC_UNREGISTERED_ADDR
};

typedef enum  {
	CEC_UNRECONIZED_OPCODE = 0x0,
	CEC_NOT_CORRECT_MODE_TO_RESPOND,
	CEC_CANNOT_PROVIDE_SOURCE,
	CEC_INVALID_OPERAND,
	CEC_REFUSED,
	CEC_UNABLE_TO_DETERMINE,
} cec_feature_abort_e;

typedef enum {
	DEVICE_MENU_ACTIVE = 0,
	DEVICE_MENU_INACTIVE,
} cec_device_menu_state_e;

/* cec message structure */
typedef struct {
	unsigned char msg[16];
	unsigned char msg_len;
} cec_msg_buf_t;

typedef struct {
	cec_msg_buf_t buf[2];          /* message memory */
	unsigned char power_status;
	unsigned char log_addr;
	unsigned char cec_power;
	unsigned char active_source;
	unsigned char rx_write_pos;
	unsigned char rx_read_pos;
	unsigned char rx_buf_size;
} cec_msg_t;

extern cec_msg_t cec_msg;
extern unsigned char hdmi_cec_func_config;

#endif /* _CEC_H */