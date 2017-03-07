begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file contains AML code definition in the latest ACPI spec.    Copyright (c) 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACPI_AML_H_
end_ifndef

begin_define
define|#
directive|define
name|_ACPI_AML_H_
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// ACPI AML definition
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Primary OpCode
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AML_ZERO_OP
value|0x00
end_define

begin_define
define|#
directive|define
name|AML_ONE_OP
value|0x01
end_define

begin_define
define|#
directive|define
name|AML_ALIAS_OP
value|0x06
end_define

begin_define
define|#
directive|define
name|AML_NAME_OP
value|0x08
end_define

begin_define
define|#
directive|define
name|AML_BYTE_PREFIX
value|0x0a
end_define

begin_define
define|#
directive|define
name|AML_WORD_PREFIX
value|0x0b
end_define

begin_define
define|#
directive|define
name|AML_DWORD_PREFIX
value|0x0c
end_define

begin_define
define|#
directive|define
name|AML_STRING_PREFIX
value|0x0d
end_define

begin_define
define|#
directive|define
name|AML_QWORD_PREFIX
value|0x0e
end_define

begin_define
define|#
directive|define
name|AML_SCOPE_OP
value|0x10
end_define

begin_define
define|#
directive|define
name|AML_BUFFER_OP
value|0x11
end_define

begin_define
define|#
directive|define
name|AML_PACKAGE_OP
value|0x12
end_define

begin_define
define|#
directive|define
name|AML_VAR_PACKAGE_OP
value|0x13
end_define

begin_define
define|#
directive|define
name|AML_METHOD_OP
value|0x14
end_define

begin_define
define|#
directive|define
name|AML_DUAL_NAME_PREFIX
value|0x2e
end_define

begin_define
define|#
directive|define
name|AML_MULTI_NAME_PREFIX
value|0x2f
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_A
value|0x41
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_B
value|0x42
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_C
value|0x43
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_D
value|0x44
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_E
value|0x45
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_F
value|0x46
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_G
value|0x47
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_H
value|0x48
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_I
value|0x49
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_J
value|0x4a
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_K
value|0x4b
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_L
value|0x4c
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_M
value|0x4d
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_N
value|0x4e
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_O
value|0x4f
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_P
value|0x50
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_Q
value|0x51
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_R
value|0x52
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_S
value|0x53
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_T
value|0x54
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_U
value|0x55
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_V
value|0x56
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_W
value|0x57
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_X
value|0x58
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_Y
value|0x59
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR_Z
value|0x5a
end_define

begin_define
define|#
directive|define
name|AML_ROOT_CHAR
value|0x5c
end_define

begin_define
define|#
directive|define
name|AML_PARENT_PREFIX_CHAR
value|0x5e
end_define

begin_define
define|#
directive|define
name|AML_NAME_CHAR__
value|0x5f
end_define

begin_define
define|#
directive|define
name|AML_LOCAL0
value|0x60
end_define

begin_define
define|#
directive|define
name|AML_LOCAL1
value|0x61
end_define

begin_define
define|#
directive|define
name|AML_LOCAL2
value|0x62
end_define

begin_define
define|#
directive|define
name|AML_LOCAL3
value|0x63
end_define

begin_define
define|#
directive|define
name|AML_LOCAL4
value|0x64
end_define

begin_define
define|#
directive|define
name|AML_LOCAL5
value|0x65
end_define

begin_define
define|#
directive|define
name|AML_LOCAL6
value|0x66
end_define

begin_define
define|#
directive|define
name|AML_LOCAL7
value|0x67
end_define

begin_define
define|#
directive|define
name|AML_ARG0
value|0x68
end_define

begin_define
define|#
directive|define
name|AML_ARG1
value|0x69
end_define

begin_define
define|#
directive|define
name|AML_ARG2
value|0x6a
end_define

begin_define
define|#
directive|define
name|AML_ARG3
value|0x6b
end_define

begin_define
define|#
directive|define
name|AML_ARG4
value|0x6c
end_define

begin_define
define|#
directive|define
name|AML_ARG5
value|0x6d
end_define

begin_define
define|#
directive|define
name|AML_ARG6
value|0x6e
end_define

begin_define
define|#
directive|define
name|AML_STORE_OP
value|0x70
end_define

begin_define
define|#
directive|define
name|AML_REF_OF_OP
value|0x71
end_define

begin_define
define|#
directive|define
name|AML_ADD_OP
value|0x72
end_define

begin_define
define|#
directive|define
name|AML_CONCAT_OP
value|0x73
end_define

begin_define
define|#
directive|define
name|AML_SUBTRACT_OP
value|0x74
end_define

begin_define
define|#
directive|define
name|AML_INCREMENT_OP
value|0x75
end_define

begin_define
define|#
directive|define
name|AML_DECREMENT_OP
value|0x76
end_define

begin_define
define|#
directive|define
name|AML_MULTIPLY_OP
value|0x77
end_define

begin_define
define|#
directive|define
name|AML_DIVIDE_OP
value|0x78
end_define

begin_define
define|#
directive|define
name|AML_SHIFT_LEFT_OP
value|0x79
end_define

begin_define
define|#
directive|define
name|AML_SHIFT_RIGHT_OP
value|0x7a
end_define

begin_define
define|#
directive|define
name|AML_AND_OP
value|0x7b
end_define

begin_define
define|#
directive|define
name|AML_NAND_OP
value|0x7c
end_define

begin_define
define|#
directive|define
name|AML_OR_OP
value|0x7d
end_define

begin_define
define|#
directive|define
name|AML_NOR_OP
value|0x7e
end_define

begin_define
define|#
directive|define
name|AML_XOR_OP
value|0x7f
end_define

begin_define
define|#
directive|define
name|AML_NOT_OP
value|0x80
end_define

begin_define
define|#
directive|define
name|AML_FIND_SET_LEFT_BIT_OP
value|0x81
end_define

begin_define
define|#
directive|define
name|AML_FIND_SET_RIGHT_BIT_OP
value|0x82
end_define

begin_define
define|#
directive|define
name|AML_DEREF_OF_OP
value|0x83
end_define

begin_define
define|#
directive|define
name|AML_CONCAT_RES_OP
value|0x84
end_define

begin_define
define|#
directive|define
name|AML_MOD_OP
value|0x85
end_define

begin_define
define|#
directive|define
name|AML_NOTIFY_OP
value|0x86
end_define

begin_define
define|#
directive|define
name|AML_SIZE_OF_OP
value|0x87
end_define

begin_define
define|#
directive|define
name|AML_INDEX_OP
value|0x88
end_define

begin_define
define|#
directive|define
name|AML_MATCH_OP
value|0x89
end_define

begin_define
define|#
directive|define
name|AML_CREATE_DWORD_FIELD_OP
value|0x8a
end_define

begin_define
define|#
directive|define
name|AML_CREATE_WORD_FIELD_OP
value|0x8b
end_define

begin_define
define|#
directive|define
name|AML_CREATE_BYTE_FIELD_OP
value|0x8c
end_define

begin_define
define|#
directive|define
name|AML_CREATE_BIT_FIELD_OP
value|0x8d
end_define

begin_define
define|#
directive|define
name|AML_OBJECT_TYPE_OP
value|0x8e
end_define

begin_define
define|#
directive|define
name|AML_CREATE_QWORD_FIELD_OP
value|0x8f
end_define

begin_define
define|#
directive|define
name|AML_LAND_OP
value|0x90
end_define

begin_define
define|#
directive|define
name|AML_LOR_OP
value|0x91
end_define

begin_define
define|#
directive|define
name|AML_LNOT_OP
value|0x92
end_define

begin_define
define|#
directive|define
name|AML_LEQUAL_OP
value|0x93
end_define

begin_define
define|#
directive|define
name|AML_LGREATER_OP
value|0x94
end_define

begin_define
define|#
directive|define
name|AML_LLESS_OP
value|0x95
end_define

begin_define
define|#
directive|define
name|AML_TO_BUFFER_OP
value|0x96
end_define

begin_define
define|#
directive|define
name|AML_TO_DEC_STRING_OP
value|0x97
end_define

begin_define
define|#
directive|define
name|AML_TO_HEX_STRING_OP
value|0x98
end_define

begin_define
define|#
directive|define
name|AML_TO_INTEGER_OP
value|0x99
end_define

begin_define
define|#
directive|define
name|AML_TO_STRING_OP
value|0x9c
end_define

begin_define
define|#
directive|define
name|AML_COPY_OBJECT_OP
value|0x9d
end_define

begin_define
define|#
directive|define
name|AML_MID_OP
value|0x9e
end_define

begin_define
define|#
directive|define
name|AML_CONTINUE_OP
value|0x9f
end_define

begin_define
define|#
directive|define
name|AML_IF_OP
value|0xa0
end_define

begin_define
define|#
directive|define
name|AML_ELSE_OP
value|0xa1
end_define

begin_define
define|#
directive|define
name|AML_WHILE_OP
value|0xa2
end_define

begin_define
define|#
directive|define
name|AML_NOOP_OP
value|0xa3
end_define

begin_define
define|#
directive|define
name|AML_RETURN_OP
value|0xa4
end_define

begin_define
define|#
directive|define
name|AML_BREAK_OP
value|0xa5
end_define

begin_define
define|#
directive|define
name|AML_BREAK_POINT_OP
value|0xcc
end_define

begin_define
define|#
directive|define
name|AML_ONES_OP
value|0xff
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Extended OpCode
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|AML_EXT_OP
value|0x5b
end_define

begin_define
define|#
directive|define
name|AML_EXT_MUTEX_OP
value|0x01
end_define

begin_define
define|#
directive|define
name|AML_EXT_EVENT_OP
value|0x02
end_define

begin_define
define|#
directive|define
name|AML_EXT_COND_REF_OF_OP
value|0x12
end_define

begin_define
define|#
directive|define
name|AML_EXT_CREATE_FIELD_OP
value|0x13
end_define

begin_define
define|#
directive|define
name|AML_EXT_LOAD_TABLE_OP
value|0x1f
end_define

begin_define
define|#
directive|define
name|AML_EXT_LOAD_OP
value|0x20
end_define

begin_define
define|#
directive|define
name|AML_EXT_STALL_OP
value|0x21
end_define

begin_define
define|#
directive|define
name|AML_EXT_SLEEP_OP
value|0x22
end_define

begin_define
define|#
directive|define
name|AML_EXT_ACQUIRE_OP
value|0x23
end_define

begin_define
define|#
directive|define
name|AML_EXT_SIGNAL_OP
value|0x24
end_define

begin_define
define|#
directive|define
name|AML_EXT_WAIT_OP
value|0x25
end_define

begin_define
define|#
directive|define
name|AML_EXT_RESET_OP
value|0x26
end_define

begin_define
define|#
directive|define
name|AML_EXT_RELEASE_OP
value|0x27
end_define

begin_define
define|#
directive|define
name|AML_EXT_FROM_BCD_OP
value|0x28
end_define

begin_define
define|#
directive|define
name|AML_EXT_TO_BCD_OP
value|0x29
end_define

begin_define
define|#
directive|define
name|AML_EXT_UNLOAD_OP
value|0x2a
end_define

begin_define
define|#
directive|define
name|AML_EXT_REVISION_OP
value|0x30
end_define

begin_define
define|#
directive|define
name|AML_EXT_DEBUG_OP
value|0x31
end_define

begin_define
define|#
directive|define
name|AML_EXT_FATAL_OP
value|0x32
end_define

begin_define
define|#
directive|define
name|AML_EXT_TIMER_OP
value|0x33
end_define

begin_define
define|#
directive|define
name|AML_EXT_REGION_OP
value|0x80
end_define

begin_define
define|#
directive|define
name|AML_EXT_FIELD_OP
value|0x81
end_define

begin_define
define|#
directive|define
name|AML_EXT_DEVICE_OP
value|0x82
end_define

begin_define
define|#
directive|define
name|AML_EXT_PROCESSOR_OP
value|0x83
end_define

begin_define
define|#
directive|define
name|AML_EXT_POWER_RES_OP
value|0x84
end_define

begin_define
define|#
directive|define
name|AML_EXT_THERMAL_ZONE_OP
value|0x85
end_define

begin_define
define|#
directive|define
name|AML_EXT_INDEX_FIELD_OP
value|0x86
end_define

begin_define
define|#
directive|define
name|AML_EXT_BANK_FIELD_OP
value|0x87
end_define

begin_define
define|#
directive|define
name|AML_EXT_DATA_REGION_OP
value|0x88
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

