begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-04 3ware, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * 3ware driver for 9000 series storage controllers.  *  * Author: Vinod Kashyap  */
end_comment

begin_include
include|#
directive|include
file|<dev/twa/twa_includes.h>
end_include

begin_comment
comment|/* AEN messages. */
end_comment

begin_decl_stmt
name|struct
name|twa_message
name|twa_aen_table
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"AEN queue empty"
block|}
block|,
block|{
literal|0x0001
block|,
literal|"Controller reset occurred"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"Degraded unit detected"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"Controller error occured"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"Background rebuild failed"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"Background rebuild done"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"Incomplete unit detected"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"Background initialize done"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"Unclean shutdown detected"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"Drive timeout detected"
block|}
block|,
block|{
literal|0x000A
block|,
literal|"Drive error detected"
block|}
block|,
block|{
literal|0x000B
block|,
literal|"Rebuild started"
block|}
block|,
block|{
literal|0x000C
block|,
literal|"Background initialize started"
block|}
block|,
block|{
literal|0x000D
block|,
literal|"Entire logical unit was deleted"
block|}
block|,
block|{
literal|0x000E
block|,
literal|"Background initialize failed"
block|}
block|,
block|{
literal|0x000F
block|,
literal|"SMART attribute exceeded threshold"
block|}
block|,
block|{
literal|0x0010
block|,
literal|"Power supply reported AC under range"
block|}
block|,
block|{
literal|0x0011
block|,
literal|"Power supply reported DC out of range"
block|}
block|,
block|{
literal|0x0012
block|,
literal|"Power supply reported a malfunction"
block|}
block|,
block|{
literal|0x0013
block|,
literal|"Power supply predicted malfunction"
block|}
block|,
block|{
literal|0x0014
block|,
literal|"Battery charge is below threshold"
block|}
block|,
block|{
literal|0x0015
block|,
literal|"Fan speed is below threshold"
block|}
block|,
block|{
literal|0x0016
block|,
literal|"Temperature sensor is above threshold"
block|}
block|,
block|{
literal|0x0017
block|,
literal|"Power supply was removed"
block|}
block|,
block|{
literal|0x0018
block|,
literal|"Power supply was inserted"
block|}
block|,
block|{
literal|0x0019
block|,
literal|"Drive was removed from a bay"
block|}
block|,
block|{
literal|0x001A
block|,
literal|"Drive was inserted into a bay"
block|}
block|,
block|{
literal|0x001B
block|,
literal|"Drive bay cover door was opened"
block|}
block|,
block|{
literal|0x001C
block|,
literal|"Drive bay cover door was closed"
block|}
block|,
block|{
literal|0x001D
block|,
literal|"Product case was opened"
block|}
block|,
block|{
literal|0x0020
block|,
literal|"Prepare for shutdown (power-off)"
block|}
block|,
block|{
literal|0x0021
block|,
literal|"Downgrade UDMA mode to lower speed"
block|}
block|,
block|{
literal|0x0022
block|,
literal|"Upgrade UDMA mode to higher speed"
block|}
block|,
block|{
literal|0x0023
block|,
literal|"Sector repair completed"
block|}
block|,
block|{
literal|0x0024
block|,
literal|"Sbuf memory test failed"
block|}
block|,
block|{
literal|0x0025
block|,
literal|"Error flushing cached write data to disk"
block|}
block|,
block|{
literal|0x0026
block|,
literal|"Drive reported data ECC error"
block|}
block|,
block|{
literal|0x0027
block|,
literal|"DCB has checksum error"
block|}
block|,
block|{
literal|0x0028
block|,
literal|"DCB version is unsupported"
block|}
block|,
block|{
literal|0x0029
block|,
literal|"Background verify started"
block|}
block|,
block|{
literal|0x002A
block|,
literal|"Background verify failed"
block|}
block|,
block|{
literal|0x002B
block|,
literal|"Background verify done"
block|}
block|,
block|{
literal|0x002C
block|,
literal|"Bad sector overwritten during rebuild"
block|}
block|,
block|{
literal|0x002E
block|,
literal|"Replace failed because replacement drive too small"
block|}
block|,
block|{
literal|0x002F
block|,
literal|"Verify failed because array was never initialized"
block|}
block|,
block|{
literal|0x0030
block|,
literal|"Unsupported ATA drive"
block|}
block|,
block|{
literal|0x0031
block|,
literal|"Synchronize host/controller time"
block|}
block|,
block|{
literal|0x0032
block|,
literal|"Spare capacity is inadequate for some units"
block|}
block|,
block|{
literal|0x0033
block|,
literal|"Background migration started"
block|}
block|,
block|{
literal|0x0034
block|,
literal|"Background migration failed"
block|}
block|,
block|{
literal|0x0035
block|,
literal|"Background migration done"
block|}
block|,
block|{
literal|0x0036
block|,
literal|"Verify detected and fixed data/parity mismatch"
block|}
block|,
block|{
literal|0x0037
block|,
literal|"SO-DIMM incompatible"
block|}
block|,
block|{
literal|0x0038
block|,
literal|"SO-DIMM not detected"
block|}
block|,
block|{
literal|0x0039
block|,
literal|"Corrected Sbuf ECC error"
block|}
block|,
block|{
literal|0x003A
block|,
literal|"Drive power on reset detected"
block|}
block|,
block|{
literal|0x003B
block|,
literal|"Background rebuild paused"
block|}
block|,
block|{
literal|0x003C
block|,
literal|"Background initialize paused"
block|}
block|,
block|{
literal|0x003D
block|,
literal|"Background verify paused"
block|}
block|,
block|{
literal|0x003E
block|,
literal|"Background migration paused"
block|}
block|,
block|{
literal|0x003F
block|,
literal|"Corrupt flash file system detected"
block|}
block|,
block|{
literal|0x0040
block|,
literal|"Flash file system repaired"
block|}
block|,
block|{
literal|0x0041
block|,
literal|"Unit number assignments were lost"
block|}
block|,
block|{
literal|0x0042
block|,
literal|"Error during read of primary DCB"
block|}
block|,
block|{
literal|0x0043
block|,
literal|"Latent error found in backup DCB"
block|}
block|,
block|{
literal|0x0044
block|,
literal|"Voltage is within normal range"
block|}
block|,
block|{
literal|0x0045
block|,
literal|"Voltage is in low warning range"
block|}
block|,
block|{
literal|0x0046
block|,
literal|"Voltage is in high warning range"
block|}
block|,
block|{
literal|0x0047
block|,
literal|"Voltage is below operating range"
block|}
block|,
block|{
literal|0x0048
block|,
literal|"Voltage is above operating range"
block|}
block|,
block|{
literal|0x0049
block|,
literal|"Temperature is within normal range"
block|}
block|,
block|{
literal|0x004A
block|,
literal|"Temperature is in low warning range"
block|}
block|,
block|{
literal|0x004B
block|,
literal|"Temperature is high warning range"
block|}
block|,
block|{
literal|0x004C
block|,
literal|"Temperature is below operating range"
block|}
block|,
block|{
literal|0x004D
block|,
literal|"Temperature is above operating range"
block|}
block|,
block|{
literal|0x004E
block|,
literal|"Low current test started"
block|}
block|,
block|{
literal|0x0050
block|,
literal|"Low current test stopped"
block|}
block|,
block|{
literal|0x0051
block|,
literal|"High current test started"
block|}
block|,
block|{
literal|0x0052
block|,
literal|"High current test stopped"
block|}
block|,
block|{
literal|0x0053
block|,
literal|"Charge termination voltage is at high level"
block|}
block|,
block|{
literal|0x0054
block|,
literal|"Charge termination voltage is at high level"
block|}
block|,
block|{
literal|0x0055
block|,
literal|"Charge started"
block|}
block|,
block|{
literal|0x0056
block|,
literal|"Charge stopped"
block|}
block|,
block|{
literal|0x0057
block|,
literal|"Charge is in fault condition"
block|}
block|,
block|{
literal|0x0058
block|,
literal|"Capacity is below warning level"
block|}
block|,
block|{
literal|0x0059
block|,
literal|"Capacity is below error level"
block|}
block|,
block|{
literal|0x005A
block|,
literal|"Battery is present"
block|}
block|,
block|{
literal|0x005B
block|,
literal|"Battery is not present"
block|}
block|,
block|{
literal|0x005C
block|,
literal|"High current test is in warning level"
block|}
block|,
block|{
literal|0x005D
block|,
literal|"High current test is in fault level"
block|}
block|,
block|{
literal|0x0060
block|,
literal|"Bad cache meta data checksum"
block|}
block|,
block|{
literal|0x0061
block|,
literal|"Bad cache meta data signature"
block|}
block|,
block|{
literal|0x0062
block|,
literal|"Cache meta data restore failed"
block|}
block|,
block|{
literal|0x0063
block|,
literal|"Cache meta data was lost"
block|}
block|,
block|{
literal|0x0064
block|,
literal|"Cache write data sync failed"
block|}
block|,
block|{
literal|0x0065
block|,
literal|"Not able to sync cache write data"
block|}
block|,
block|{
literal|0x00FC
block|,
literal|"Recovered/finished array membership update"
block|}
block|,
block|{
literal|0x00FD
block|,
literal|"Handler lockup"
block|}
block|,
block|{
literal|0x00FE
block|,
literal|"Retrying PCI transfer"
block|}
block|,
block|{
literal|0x00FF
block|,
literal|"AEN queue is full"
block|}
block|,
block|{
literal|0xFFFFFFFF
block|,
literal|""
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* AEN severity table. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|twa_aen_severity_table
index|[]
init|=
block|{
literal|"None"
block|,
literal|"ERROR"
block|,
literal|"WARNING"
block|,
literal|"INFO"
block|,
literal|"DEBUG"
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Error messages. */
end_comment

begin_decl_stmt
name|struct
name|twa_message
name|twa_error_table
index|[]
init|=
block|{
block|{
literal|0x0100
block|,
literal|"SGL entry contains zero data"
block|}
block|,
block|{
literal|0x0101
block|,
literal|"Invalid command opcode"
block|}
block|,
block|{
literal|0x0102
block|,
literal|"SGL entry has unaligned address"
block|}
block|,
block|{
literal|0x0103
block|,
literal|"SGL size does not match command"
block|}
block|,
block|{
literal|0x0104
block|,
literal|"SGL entry has illegal length"
block|}
block|,
block|{
literal|0x0105
block|,
literal|"Command packet is not aligned"
block|}
block|,
block|{
literal|0x0106
block|,
literal|"Invalid request ID"
block|}
block|,
block|{
literal|0x0107
block|,
literal|"Duplicate request ID"
block|}
block|,
block|{
literal|0x0108
block|,
literal|"ID not locked"
block|}
block|,
block|{
literal|0x0109
block|,
literal|"LBA out of range"
block|}
block|,
block|{
literal|0x010A
block|,
literal|"Logical unit not supported"
block|}
block|,
block|{
literal|0x010B
block|,
literal|"Parameter table does not exist"
block|}
block|,
block|{
literal|0x010C
block|,
literal|"Parameter index does not exist"
block|}
block|,
block|{
literal|0x010D
block|,
literal|"Invalid field in CDB"
block|}
block|,
block|{
literal|0x010E
block|,
literal|"Specified port has invalid drive"
block|}
block|,
block|{
literal|0x010F
block|,
literal|"Parameter item size mismatch"
block|}
block|,
block|{
literal|0x0110
block|,
literal|"Failed memory allocation"
block|}
block|,
block|{
literal|0x0111
block|,
literal|"Memory request too large"
block|}
block|,
block|{
literal|0x0112
block|,
literal|"Out of memory segments"
block|}
block|,
block|{
literal|0x0113
block|,
literal|"Invalid address to deallocate"
block|}
block|,
block|{
literal|0x0114
block|,
literal|"Out of memory"
block|}
block|,
block|{
literal|0x0115
block|,
literal|"Out of heap"
block|}
block|,
block|{
literal|0x0120
block|,
literal|"Double degrade"
block|}
block|,
block|{
literal|0x0121
block|,
literal|"Drive not degraded"
block|}
block|,
block|{
literal|0x0122
block|,
literal|"Reconstruct error"
block|}
block|,
block|{
literal|0x0123
block|,
literal|"Replace not accepted"
block|}
block|,
block|{
literal|0x0124
block|,
literal|"Drive capacity too small"
block|}
block|,
block|{
literal|0x0125
block|,
literal|"Sector count not allowed"
block|}
block|,
block|{
literal|0x0126
block|,
literal|"No spares left"
block|}
block|,
block|{
literal|0x0127
block|,
literal|"Reconstruct error"
block|}
block|,
block|{
literal|0x0128
block|,
literal|"Unit is offline"
block|}
block|,
block|{
literal|0x0129
block|,
literal|"Cannot update status to DCB"
block|}
block|,
block|{
literal|0x012A
block|,
literal|"Dchnl cannot be split"
block|}
block|,
block|{
literal|0x012B
block|,
literal|"Dchnl cannot be joined"
block|}
block|,
block|{
literal|0x012C
block|,
literal|"No migration recovery"
block|}
block|,
block|{
literal|0x0130
block|,
literal|"Invalid stripe handle"
block|}
block|,
block|{
literal|0x0131
block|,
literal|"Handle that was not locked"
block|}
block|,
block|{
literal|0x0132
block|,
literal|"Handle that was not empty"
block|}
block|,
block|{
literal|0x0133
block|,
literal|"Handle has different owner"
block|}
block|,
block|{
literal|0x0140
block|,
literal|"IPR has parent"
block|}
block|,
block|{
literal|0x0150
block|,
literal|"Illegal Pbuf address alignment"
block|}
block|,
block|{
literal|0x0151
block|,
literal|"Illegal Pbuf transfer length"
block|}
block|,
block|{
literal|0x0152
block|,
literal|"Illegal Sbuf address alignment"
block|}
block|,
block|{
literal|0x0153
block|,
literal|"Illegal Sbuf transfer length"
block|}
block|,
block|{
literal|0x0160
block|,
literal|"Command packet too large"
block|}
block|,
block|{
literal|0x0161
block|,
literal|"SGL exceeds maximum length"
block|}
block|,
block|{
literal|0x0162
block|,
literal|"SGL has too many entries"
block|}
block|,
block|{
literal|0x0170
block|,
literal|"Insufficient resources for rebuilder"
block|}
block|,
block|{
literal|0x0171
block|,
literal|"Verify error (data != parity)"
block|}
block|,
block|{
literal|0x0180
block|,
literal|"Requested segment not in directory of this DCB"
block|}
block|,
block|{
literal|0x0181
block|,
literal|"DCB segment has unsupported version"
block|}
block|,
block|{
literal|0x0182
block|,
literal|"DCB segment has checksum error"
block|}
block|,
block|{
literal|0x0183
block|,
literal|"DCB support (settings) segment invalid"
block|}
block|,
block|{
literal|0x0184
block|,
literal|"DCB UDB (unit descriptor block) segment invalid"
block|}
block|,
block|{
literal|0x0185
block|,
literal|"DCB GUID (globally unique identifier) segment invalid"
block|}
block|,
block|{
literal|0x01A0
block|,
literal|"Could not clear Sbuf"
block|}
block|,
block|{
literal|0x01C0
block|,
literal|"Flash identify failed"
block|}
block|,
block|{
literal|0x01C1
block|,
literal|"Flash out of bounds"
block|}
block|,
block|{
literal|0x01C2
block|,
literal|"Flash verify error"
block|}
block|,
block|{
literal|0x01C3
block|,
literal|"Flash file object not found"
block|}
block|,
block|{
literal|0x01C4
block|,
literal|"Flash file already present"
block|}
block|,
block|{
literal|0x01C5
block|,
literal|"Flash file system full"
block|}
block|,
block|{
literal|0x01C6
block|,
literal|"Flash file not present"
block|}
block|,
block|{
literal|0x01C7
block|,
literal|"Flash file size error"
block|}
block|,
block|{
literal|0x01C8
block|,
literal|"Bad flash file checksum"
block|}
block|,
block|{
literal|0x01CA
block|,
literal|"Corrupt flash file system detected"
block|}
block|,
block|{
literal|0x01CB
block|,
literal|"Flash file has no component directory"
block|}
block|,
block|{
literal|0x01CC
block|,
literal|"Flash file component not found"
block|}
block|,
block|{
literal|0x01CD
block|,
literal|"Flash Write cycle Failed"
block|}
block|,
block|{
literal|0x01CE
block|,
literal|"Flash Erase cycle Failed"
block|}
block|,
block|{
literal|0x01D0
block|,
literal|"Invalid field in parameter list"
block|}
block|,
block|{
literal|0x01D1
block|,
literal|"Parameter list length error"
block|}
block|,
block|{
literal|0x01D2
block|,
literal|"Parameter item is not changeable"
block|}
block|,
block|{
literal|0x01D3
block|,
literal|"Parameter item is not saveable"
block|}
block|,
block|{
literal|0x0200
block|,
literal|"UDMA CRC error"
block|}
block|,
block|{
literal|0x0201
block|,
literal|"Internal CRC error"
block|}
block|,
block|{
literal|0x0202
block|,
literal|"Data ECC error"
block|}
block|,
block|{
literal|0x0203
block|,
literal|"ADP level 1 error"
block|}
block|,
block|{
literal|0x0204
block|,
literal|"Port timeout"
block|}
block|,
block|{
literal|0x0205
block|,
literal|"Drive power on reset"
block|}
block|,
block|{
literal|0x0206
block|,
literal|"ADP level 2 error"
block|}
block|,
block|{
literal|0x0207
block|,
literal|"Soft reset failed"
block|}
block|,
block|{
literal|0x0208
block|,
literal|"Drive not ready"
block|}
block|,
block|{
literal|0x0209
block|,
literal|"Unclassified port error"
block|}
block|,
block|{
literal|0x020A
block|,
literal|"Drive aborted command"
block|}
block|,
block|{
literal|0x0210
block|,
literal|"Internal CRC error"
block|}
block|,
block|{
literal|0x0211
block|,
literal|"PCI abort error"
block|}
block|,
block|{
literal|0x0212
block|,
literal|"PCI parity error"
block|}
block|,
block|{
literal|0x0213
block|,
literal|"Port handler error"
block|}
block|,
block|{
literal|0x0214
block|,
literal|"Token interrupt count error"
block|}
block|,
block|{
literal|0x0215
block|,
literal|"Timeout waiting for PCI transfer"
block|}
block|,
block|{
literal|0x0216
block|,
literal|"Corrected buffer ECC"
block|}
block|,
block|{
literal|0x0217
block|,
literal|"Uncorrected buffer ECC"
block|}
block|,
block|{
literal|0x0230
block|,
literal|"Unsupported command during flash recovery"
block|}
block|,
block|{
literal|0x0231
block|,
literal|"Next image buffer expected"
block|}
block|,
block|{
literal|0x0232
block|,
literal|"Binary image architecture incompatible"
block|}
block|,
block|{
literal|0x0233
block|,
literal|"Binary image has no signature"
block|}
block|,
block|{
literal|0x0234
block|,
literal|"Binary image has bad checksum"
block|}
block|,
block|{
literal|0x0235
block|,
literal|"Binary image overflowed buffer"
block|}
block|,
block|{
literal|0x0240
block|,
literal|"I2C device not found"
block|}
block|,
block|{
literal|0x0241
block|,
literal|"I2C transaction aborted"
block|}
block|,
block|{
literal|0x0242
block|,
literal|"SO-DIMM parameter(s) incompatible using defaults"
block|}
block|,
block|{
literal|0x0243
block|,
literal|"SO-DIMM unsupported"
block|}
block|,
block|{
literal|0x0244
block|,
literal|"I2C clock is held low - Transfer aborted"
block|}
block|,
block|{
literal|0x0245
block|,
literal|"I2C data  is held low - Transfer aborted"
block|}
block|,
block|{
literal|0x0246
block|,
literal|"I2C slave device NACKed the transfer"
block|}
block|,
block|{
literal|0x0247
block|,
literal|"I2C buffer in-sufficient"
block|}
block|,
block|{
literal|0x0248
block|,
literal|"SPI transfer status error"
block|}
block|,
block|{
literal|0x0249
block|,
literal|"SPI transfer timeout error"
block|}
block|,
block|{
literal|0x0250
block|,
literal|"Invalid unit descriptor size"
block|}
block|,
block|{
literal|0x0251
block|,
literal|"Unit descriptor size exceeds data buffer"
block|}
block|,
block|{
literal|0x0252
block|,
literal|"Invalid value in unit descriptor"
block|}
block|,
block|{
literal|0x0253
block|,
literal|"Inadequate disk space to support descriptor"
block|}
block|,
block|{
literal|0x0254
block|,
literal|"Unable to create data channel for this unit descriptor"
block|}
block|,
block|{
literal|0x0255
block|,
literal|"CreateUnit descriptor specifies a drive already in use"
block|}
block|,
block|{
literal|0x0256
block|,
literal|"Unable to write configuration to all disks during CreateUnit"
block|}
block|,
block|{
literal|0x0257
block|,
literal|"CreateUnit/MigrateUnit does not support this descriptor version"
block|}
block|,
block|{
literal|0x0258
block|,
literal|"Invalid subunit for RAID 0 or 5 in CreateUnit/MigrateUnit"
block|}
block|,
block|{
literal|0x0259
block|,
literal|"Too many descriptors in CreateUnit/MigrateUnit"
block|}
block|,
block|{
literal|0x025A
block|,
literal|"Invalid configuration specified in unit descriptor"
block|}
block|,
block|{
literal|0x025B
block|,
literal|"Invalid LBA offset specified in unit descriptor"
block|}
block|,
block|{
literal|0x025C
block|,
literal|"Invalid stripelet size specified in unit descriptor"
block|}
block|,
block|{
literal|0x025D
block|,
literal|"JBOD unit is not allowed"
block|}
block|,
block|{
literal|0x0260
block|,
literal|"SMART attribute exceeded threshold"
block|}
block|,
block|{
literal|0x0270
block|,
literal|"Unit is not in NORMAL state"
block|}
block|,
block|{
literal|0x0271
block|,
literal|"Invalid drive members"
block|}
block|,
block|{
literal|0x0272
block|,
literal|"Converted unit is not supported"
block|}
block|,
block|{
literal|0x0300
block|,
literal|"Internal errorcode (BBU base) - should not occur"
block|}
block|,
block|{
literal|0x0301
block|,
literal|"Invalid BBU state change request"
block|}
block|,
block|{
literal|0x0302
block|,
literal|"The BBU resource needed is in use ; retry command after a delay"
block|}
block|,
block|{
literal|0x0303
block|,
literal|"Command requires a battery pack to be present and enabled"
block|}
block|,
block|{
literal|0x0310
block|,
literal|"BBU command packet error"
block|}
block|,
block|{
literal|0x0311
block|,
literal|"BBU command not implemented"
block|}
block|,
block|{
literal|0x0312
block|,
literal|"BBU command buffer underflow"
block|}
block|,
block|{
literal|0x0313
block|,
literal|"BBU command buffer overflow"
block|}
block|,
block|{
literal|0x0314
block|,
literal|"BBU command incomplete"
block|}
block|,
block|{
literal|0x0315
block|,
literal|"BBU command checksum error"
block|}
block|,
block|{
literal|0x0316
block|,
literal|"BBU command timeout"
block|}
block|,
block|{
literal|0x0320
block|,
literal|"BBU parameter not defined"
block|}
block|,
block|{
literal|0x0321
block|,
literal|"BBU parameter size mismatch"
block|}
block|,
block|{
literal|0x0322
block|,
literal|"Cannot write a read-only BBU parameter"
block|}
block|,
block|{
literal|0x0323
block|,
literal|"BBU firmware version string not found"
block|}
block|,
block|{
literal|0x0324
block|,
literal|"BBU operating state not available"
block|}
block|,
block|{
literal|0x0325
block|,
literal|"BBU not present"
block|}
block|,
block|{
literal|0x0326
block|,
literal|"BBU not ready"
block|}
block|,
block|{
literal|0x0327
block|,
literal|"BBU S1 not compatible with HBA"
block|}
block|,
block|{
literal|0x0328
block|,
literal|"BBU S0 not compatible with HBA"
block|}
block|,
block|{
literal|0x0329
block|,
literal|"BBU not compatible with HBA"
block|}
block|,
block|{
literal|0x032A
block|,
literal|"BBU not in S0"
block|}
block|,
block|{
literal|0x032B
block|,
literal|"BBU not in S1"
block|}
block|,
block|{
literal|0x032C
block|,
literal|"Timeout on BBU power fail interrupt"
block|}
block|,
block|{
literal|0x032D
block|,
literal|"BBU command checksum error"
block|}
block|,
block|{
literal|0x0330
block|,
literal|"Log updates not allowed"
block|}
block|,
block|{
literal|0x0331
block|,
literal|"Logs are invalid"
block|}
block|,
block|{
literal|0x0332
block|,
literal|"Logs not found"
block|}
block|,
block|{
literal|0xFFFFFFFF
block|,
literal|""
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TWA_DEBUG
end_ifdef

begin_comment
comment|/*  * Save the debug levels in global variables, so that  * their values can be changed from the debugger.  */
end_comment

begin_decl_stmt
name|u_int8_t
name|twa_dbg_level
init|=
name|TWA_DEBUG
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int8_t
name|twa_call_dbg_level
init|=
name|TWA_DEBUG
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TWA_DEBUG */
end_comment

end_unit

