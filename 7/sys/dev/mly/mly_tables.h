begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * Lookup table for code-to-text translations.  */
end_comment

begin_struct
struct|struct
name|mly_code_lookup
block|{
name|char
modifier|*
name|string
decl_stmt|;
name|u_int32_t
name|code
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|static
name|char
modifier|*
name|mly_describe_code
parameter_list|(
name|struct
name|mly_code_lookup
modifier|*
name|table
parameter_list|,
name|u_int32_t
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/********************************************************************************  * Look up a text description of a numeric code and return a pointer to same.  */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|mly_describe_code
parameter_list|(
name|struct
name|mly_code_lookup
modifier|*
name|table
parameter_list|,
name|u_int32_t
name|code
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|table
index|[
name|i
index|]
operator|.
name|string
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|table
index|[
name|i
index|]
operator|.
name|code
operator|==
name|code
condition|)
return|return
operator|(
name|table
index|[
name|i
index|]
operator|.
name|string
operator|)
return|;
return|return
operator|(
name|table
index|[
name|i
operator|+
literal|1
index|]
operator|.
name|string
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static struct mly_code_lookup mly_table_bustype[] = {     {"SCSI",		0x00},     {"FC-AL",		0x01},     {"PCI",		0x03},     {NULL,		0},     {"unknown bus",	0} };
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|struct
name|mly_code_lookup
name|mly_table_controllertype
index|[]
init|=
block|{
if|#
directive|if
literal|0
comment|/* not supported by this driver */
block|{"DAC960E",		0x01},
comment|/* EISA */
block|{"DAC960M",		0x08},
comment|/* MCA */
block|{"DAC960PD",	0x10},
comment|/* PCI Dual */
block|{"DAC960PL",	0x11},
comment|/* PCU low-cost */
block|{"DAC960PDU",	0x12},
comment|/* PD Ultra */
block|{"DAC960PE",	0x13},
comment|/* Peregrine low-cost */
block|{"DAC960PG",	0x14},
comment|/* Peregrine high-performance */
block|{"DAC960PJ",	0x15},
comment|/* Road Runner */
block|{"DAC960PTL0",	0x16},
comment|/* Jaguar */
block|{"DAC960PR",	0x17},
comment|/* Road Runner (again?) */
block|{"DAC960PRL",	0x18},
comment|/* Tomcat */
block|{"DAC960PT",	0x19},
comment|/* Road Runner (yet again?) */
block|{"DAC1164P",	0x1a},
comment|/* Little Apple */
block|{"DAC960PTL1",	0x1b},
comment|/* Jaguar+ */
endif|#
directive|endif
block|{
literal|"EXR2000P"
block|,
literal|0x1c
block|}
block|,
comment|/* Big Apple */
block|{
literal|"EXR3000P"
block|,
literal|0x1d
block|}
block|,
comment|/* Fibre Apple */
block|{
literal|"AcceleRAID 352"
block|,
literal|0x1e
block|}
block|,
comment|/* Leopard */
block|{
literal|"AcceleRAID 170"
block|,
literal|0x1f
block|}
block|,
comment|/* Lynx */
block|{
literal|"AcceleRAID 160"
block|,
literal|0x20
block|}
block|,
comment|/* Bobcat */
block|{
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"unknown adapter"
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|mly_code_lookup
name|mly_table_oemname
index|[]
init|=
block|{
block|{
literal|"Mylex"
block|,
name|MLY_OEM_MYLEX
block|}
block|,
block|{
literal|"IBM"
block|,
name|MLY_OEM_IBM
block|}
block|,
block|{
literal|"Hewlett-Packard"
block|,
name|MLY_OEM_HP
block|}
block|,
block|{
literal|"DEC/Compaq"
block|,
name|MLY_OEM_DEC
block|}
block|,
block|{
literal|"Siemens"
block|,
name|MLY_OEM_SIEMENS
block|}
block|,
block|{
literal|"Intel"
block|,
name|MLY_OEM_INTEL
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"unknown OEM"
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|mly_code_lookup
name|mly_table_memorytype
index|[]
init|=
block|{
block|{
literal|"DRAM"
block|,
literal|0x01
block|}
block|,
block|{
literal|"EDRAM"
block|,
literal|0x02
block|}
block|,
block|{
literal|"EDO RAM"
block|,
literal|0x03
block|}
block|,
block|{
literal|"SDRAM"
block|,
literal|0x04
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"unknown memory"
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|mly_code_lookup
name|mly_table_cputype
index|[]
init|=
block|{
block|{
literal|"i960CA"
block|,
literal|0x01
block|}
block|,
block|{
literal|"i960RD"
block|,
literal|0x02
block|}
block|,
block|{
literal|"i960RN"
block|,
literal|0x03
block|}
block|,
block|{
literal|"i960RP"
block|,
literal|0x04
block|}
block|,
block|{
literal|"NorthBay(?)"
block|,
literal|0x05
block|}
block|,
block|{
literal|"StrongArm"
block|,
literal|0x06
block|}
block|,
block|{
literal|"i960RM"
block|,
literal|0x07
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"unknown CPU"
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This table is directly derived from the corresponding table in the  * Linux driver, and uses a derivative encoding for simplicity's sake.  *  * The first character of the string determines the format of the message.  *  * p  "physical device<channel>:<target><text>"	(physical device status)  * s  "physical device<channel>:<target><text>"	(scsi message or error)  *    "  sense key<key>  asc<asc>  ascq<ascq>"  *    "  info<info>   csi<csi>"  * l  "logical drive<unit>:<text>"			(logical device status)  * m  "logical drive<unit>:<text>"			(logical device message)  *  * Messages which are typically suppressed have the first character capitalised.  * These messages will only be printed if bootverbose is set.  *  * The second character in the string indicates an action to be taken as a  * result of the event.  *  * r	rescan the device for possible state change  *  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|mly_code_lookup
name|mly_table_event
index|[]
init|=
block|{
comment|/* physical device events (0x0000 - 0x007f) */
block|{
literal|"pr online"
block|,
literal|0x0001
block|}
block|,
block|{
literal|"pr standby"
block|,
literal|0x0002
block|}
block|,
block|{
literal|"p  automatic rebuild started"
block|,
literal|0x0005
block|}
block|,
block|{
literal|"p  manual rebuild started"
block|,
literal|0x0006
block|}
block|,
block|{
literal|"pr rebuild completed"
block|,
literal|0x0007
block|}
block|,
block|{
literal|"pr rebuild cancelled"
block|,
literal|0x0008
block|}
block|,
block|{
literal|"pr rebuild failed for unknown reasons"
block|,
literal|0x0009
block|}
block|,
block|{
literal|"pr rebuild failed due to new physical device"
block|,
literal|0x000a
block|}
block|,
block|{
literal|"pr rebuild failed due to logical drive failure"
block|,
literal|0x000b
block|}
block|,
block|{
literal|"sr offline"
block|,
literal|0x000c
block|}
block|,
block|{
literal|"pr found"
block|,
literal|0x000d
block|}
block|,
block|{
literal|"pr gone"
block|,
literal|0x000e
block|}
block|,
block|{
literal|"p  unconfigured"
block|,
literal|0x000f
block|}
block|,
block|{
literal|"p  expand capacity started"
block|,
literal|0x0010
block|}
block|,
block|{
literal|"pr expand capacity completed"
block|,
literal|0x0011
block|}
block|,
block|{
literal|"pr expand capacity failed"
block|,
literal|0x0012
block|}
block|,
block|{
literal|"p  parity error"
block|,
literal|0x0016
block|}
block|,
block|{
literal|"p  soft error"
block|,
literal|0x0017
block|}
block|,
block|{
literal|"p  miscellaneous error"
block|,
literal|0x0018
block|}
block|,
block|{
literal|"p  reset"
block|,
literal|0x0019
block|}
block|,
block|{
literal|"p  active spare found"
block|,
literal|0x001a
block|}
block|,
block|{
literal|"p  warm spare found"
block|,
literal|0x001b
block|}
block|,
block|{
literal|"s  sense data received"
block|,
literal|0x001c
block|}
block|,
block|{
literal|"p  initialization started"
block|,
literal|0x001d
block|}
block|,
block|{
literal|"pr initialization completed"
block|,
literal|0x001e
block|}
block|,
block|{
literal|"pr initialization failed"
block|,
literal|0x001f
block|}
block|,
block|{
literal|"pr initialization cancelled"
block|,
literal|0x0020
block|}
block|,
block|{
literal|"P  write recovery failed"
block|,
literal|0x0021
block|}
block|,
block|{
literal|"p  scsi bus reset failed"
block|,
literal|0x0022
block|}
block|,
block|{
literal|"p  double check condition"
block|,
literal|0x0023
block|}
block|,
block|{
literal|"p  device cannot be accessed"
block|,
literal|0x0024
block|}
block|,
block|{
literal|"p  gross error on scsi processor"
block|,
literal|0x0025
block|}
block|,
block|{
literal|"p  bad tag from device"
block|,
literal|0x0026
block|}
block|,
block|{
literal|"p  command timeout"
block|,
literal|0x0027
block|}
block|,
block|{
literal|"pr system reset"
block|,
literal|0x0028
block|}
block|,
block|{
literal|"p  busy status or parity error"
block|,
literal|0x0029
block|}
block|,
block|{
literal|"pr host set device to failed state"
block|,
literal|0x002a
block|}
block|,
block|{
literal|"pr selection timeout"
block|,
literal|0x002b
block|}
block|,
block|{
literal|"p  scsi bus phase error"
block|,
literal|0x002c
block|}
block|,
block|{
literal|"pr device returned unknown status"
block|,
literal|0x002d
block|}
block|,
block|{
literal|"pr device not ready"
block|,
literal|0x002e
block|}
block|,
block|{
literal|"p  device not found at startup"
block|,
literal|0x002f
block|}
block|,
block|{
literal|"p  COD write operation failed"
block|,
literal|0x0030
block|}
block|,
block|{
literal|"p  BDT write operation failed"
block|,
literal|0x0031
block|}
block|,
block|{
literal|"p  missing at startup"
block|,
literal|0x0039
block|}
block|,
block|{
literal|"p  start rebuild failed due to physical drive too small"
block|,
literal|0x003a
block|}
block|,
comment|/* logical device events (0x0080 - 0x00ff) */
block|{
literal|"m  consistency check started"
block|,
literal|0x0080
block|}
block|,
block|{
literal|"mr consistency check completed"
block|,
literal|0x0081
block|}
block|,
block|{
literal|"mr consistency check cancelled"
block|,
literal|0x0082
block|}
block|,
block|{
literal|"mr consistency check completed with errors"
block|,
literal|0x0083
block|}
block|,
block|{
literal|"mr consistency check failed due to logical drive failure"
block|,
literal|0x0084
block|}
block|,
block|{
literal|"mr consistency check failed due to physical device failure"
block|,
literal|0x0085
block|}
block|,
block|{
literal|"lr offline"
block|,
literal|0x0086
block|}
block|,
block|{
literal|"lr critical"
block|,
literal|0x0087
block|}
block|,
block|{
literal|"lr online"
block|,
literal|0x0088
block|}
block|,
block|{
literal|"m  automatic rebuild started"
block|,
literal|0x0089
block|}
block|,
block|{
literal|"m  manual rebuild started"
block|,
literal|0x008a
block|}
block|,
block|{
literal|"mr rebuild completed"
block|,
literal|0x008b
block|}
block|,
block|{
literal|"mr rebuild cancelled"
block|,
literal|0x008c
block|}
block|,
block|{
literal|"mr rebuild failed for unknown reasons"
block|,
literal|0x008d
block|}
block|,
block|{
literal|"mr rebuild failed due to new physical device"
block|,
literal|0x008e
block|}
block|,
block|{
literal|"mr rebuild failed due to logical drive failure"
block|,
literal|0x008f
block|}
block|,
block|{
literal|"l  initialization started"
block|,
literal|0x0090
block|}
block|,
block|{
literal|"lr initialization completed"
block|,
literal|0x0091
block|}
block|,
block|{
literal|"lr initialization cancelled"
block|,
literal|0x0092
block|}
block|,
block|{
literal|"lr initialization failed"
block|,
literal|0x0093
block|}
block|,
block|{
literal|"lr found"
block|,
literal|0x0094
block|}
block|,
block|{
literal|"lr gone"
block|,
literal|0x0095
block|}
block|,
block|{
literal|"l  expand capacity started"
block|,
literal|0x0096
block|}
block|,
block|{
literal|"lr expand capacity completed"
block|,
literal|0x0097
block|}
block|,
block|{
literal|"lr expand capacity failed"
block|,
literal|0x0098
block|}
block|,
block|{
literal|"l  bad block found"
block|,
literal|0x0099
block|}
block|,
block|{
literal|"lr size changed"
block|,
literal|0x009a
block|}
block|,
block|{
literal|"lr type changed"
block|,
literal|0x009b
block|}
block|,
block|{
literal|"l  bad data block found"
block|,
literal|0x009c
block|}
block|,
block|{
literal|"l  read of data block in bdt"
block|,
literal|0x009e
block|}
block|,
block|{
literal|"l  write back data for disk block lost"
block|,
literal|0x009f
block|}
block|,
comment|/* enclosure management events (0x0100 - 0x017f) */
block|{
literal|"e  enclosure %d fan %d failed"
block|,
literal|0x0140
block|}
block|,
block|{
literal|"e  enclosure %d fan %d ok"
block|,
literal|0x0141
block|}
block|,
block|{
literal|"e  enclosure %d fan %d not present"
block|,
literal|0x0142
block|}
block|,
block|{
literal|"e  enclosure %d power supply %d failed"
block|,
literal|0x0143
block|}
block|,
block|{
literal|"e  enclosure %d power supply %d ok"
block|,
literal|0x0144
block|}
block|,
block|{
literal|"e  enclosure %d power supply %d not present"
block|,
literal|0x0145
block|}
block|,
block|{
literal|"e  enclosure %d temperature sensor %d failed"
block|,
literal|0x0146
block|}
block|,
block|{
literal|"e  enclosure %d temperature sensor %d critical"
block|,
literal|0x0147
block|}
block|,
block|{
literal|"e  enclosure %d temperature sensor %d ok"
block|,
literal|0x0148
block|}
block|,
block|{
literal|"e  enclosure %d temperature sensor %d not present"
block|,
literal|0x0149
block|}
block|,
block|{
literal|"e  enclosure %d unit %d access critical"
block|,
literal|0x014a
block|}
block|,
block|{
literal|"e  enclosure %d unit %d access ok"
block|,
literal|0x014b
block|}
block|,
block|{
literal|"e  enclosure %d unit %d access offline"
block|,
literal|0x014c
block|}
block|,
comment|/* controller events (0x0180 - 0x01ff) */
block|{
literal|"c  cache write back error"
block|,
literal|0x0181
block|}
block|,
block|{
literal|"c  battery backup unit found"
block|,
literal|0x0188
block|}
block|,
block|{
literal|"c  battery backup unit charge level low"
block|,
literal|0x0189
block|}
block|,
block|{
literal|"c  battery backup unit charge level ok"
block|,
literal|0x018a
block|}
block|,
block|{
literal|"c  installation aborted"
block|,
literal|0x0193
block|}
block|,
block|{
literal|"c  mirror race recovery in progress"
block|,
literal|0x0195
block|}
block|,
block|{
literal|"c  mirror race on critical drive"
block|,
literal|0x0196
block|}
block|,
block|{
literal|"c  memory soft ecc error"
block|,
literal|0x019e
block|}
block|,
block|{
literal|"c  memory hard ecc error"
block|,
literal|0x019f
block|}
block|,
block|{
literal|"c  battery backup unit failed"
block|,
literal|0x01a2
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"?  unknown event code"
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Values here must be 16 characters or less, as they are packed into  * the 'product' field in the SCSI inquiry data.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|mly_code_lookup
name|mly_table_device_state
index|[]
init|=
block|{
block|{
literal|"offline"
block|,
name|MLY_DEVICE_STATE_OFFLINE
block|}
block|,
block|{
literal|"unconfigured"
block|,
name|MLY_DEVICE_STATE_UNCONFIGURED
block|}
block|,
block|{
literal|"online"
block|,
name|MLY_DEVICE_STATE_ONLINE
block|}
block|,
block|{
literal|"critical"
block|,
name|MLY_DEVICE_STATE_CRITICAL
block|}
block|,
block|{
literal|"writeonly"
block|,
name|MLY_DEVICE_STATE_WRITEONLY
block|}
block|,
block|{
literal|"standby"
block|,
name|MLY_DEVICE_STATE_STANDBY
block|}
block|,
block|{
literal|"missing"
block|,
name|MLY_DEVICE_STATE_MISSING
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"unknown state"
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Values here must be 8 characters or less, as they are packed into  * the 'vendor' field in the SCSI inquiry data.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|mly_code_lookup
name|mly_table_device_type
index|[]
init|=
block|{
block|{
literal|"RAID 0"
block|,
name|MLY_DEVICE_TYPE_RAID0
block|}
block|,
block|{
literal|"RAID 1"
block|,
name|MLY_DEVICE_TYPE_RAID1
block|}
block|,
block|{
literal|"RAID 3"
block|,
name|MLY_DEVICE_TYPE_RAID3
block|}
block|,
comment|/* right asymmetric parity */
block|{
literal|"RAID 5"
block|,
name|MLY_DEVICE_TYPE_RAID5
block|}
block|,
comment|/* right asymmetric parity */
block|{
literal|"RAID 6"
block|,
name|MLY_DEVICE_TYPE_RAID6
block|}
block|,
comment|/* Mylex RAID 6 */
block|{
literal|"RAID 7"
block|,
name|MLY_DEVICE_TYPE_RAID7
block|}
block|,
comment|/* JBOD */
block|{
literal|"SPAN"
block|,
name|MLY_DEVICE_TYPE_NEWSPAN
block|}
block|,
comment|/* New Mylex SPAN */
block|{
literal|"RAID 3"
block|,
name|MLY_DEVICE_TYPE_RAID3F
block|}
block|,
comment|/* fixed parity */
block|{
literal|"RAID 3"
block|,
name|MLY_DEVICE_TYPE_RAID3L
block|}
block|,
comment|/* left symmetric parity */
block|{
literal|"SPAN"
block|,
name|MLY_DEVICE_TYPE_SPAN
block|}
block|,
comment|/* current spanning implementation */
block|{
literal|"RAID 5"
block|,
name|MLY_DEVICE_TYPE_RAID5L
block|}
block|,
comment|/* left symmetric parity */
block|{
literal|"RAID E"
block|,
name|MLY_DEVICE_TYPE_RAIDE
block|}
block|,
comment|/* concatenation */
block|{
literal|"PHYSICAL"
block|,
name|MLY_DEVICE_TYPE_PHYSICAL
block|}
block|,
comment|/* physical device */
block|{
name|NULL
block|,
literal|0
block|}
block|,
block|{
literal|"UNKNOWN"
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static struct mly_code_lookup mly_table_stripe_size[] = {     {"NONE",		MLY_STRIPE_ZERO},     {"512B",		MLY_STRIPE_512b},     {"1k",		MLY_STRIPE_1k},     {"2k",		MLY_STRIPE_2k},     {"4k",		MLY_STRIPE_4k},     {"8k",		MLY_STRIPE_8k},     {"16k",		MLY_STRIPE_16k},     {"32k",		MLY_STRIPE_32k},     {"64k",		MLY_STRIPE_64k},     {"128k",		MLY_STRIPE_128k},     {"256k",		MLY_STRIPE_256k},     {"512k",		MLY_STRIPE_512k},     {"1M",		MLY_STRIPE_1m},     {NULL, 0},     {"unknown",		0} };  static struct mly_code_lookup mly_table_cacheline_size[] = {     {"NONE",		MLY_CACHELINE_ZERO},     {"512B",		MLY_CACHELINE_512b},     {"1k",		MLY_CACHELINE_1k},     {"2k",		MLY_CACHELINE_2k},     {"4k",		MLY_CACHELINE_4k},     {"8k",		MLY_CACHELINE_8k},     {"16k",		MLY_CACHELINE_16k},     {"32k",		MLY_CACHELINE_32k},     {"64k",		MLY_CACHELINE_64k},     {NULL, 0},     {"unknown",		0} };
endif|#
directive|endif
end_endif

end_unit

