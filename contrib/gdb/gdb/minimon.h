begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions and macros for support of AMD's remote debugger, MiniMON.    Copyright (C) 1990, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/*  * Some basic types.  FIXME, this should be done by declaring bitfield  * sizes in the structs.  We can't portably depend on a "long int" being  * 32 bits, etc.  */
end_comment

begin_typedef
typedef|typedef
name|long
name|int
name|INT32
typedef|;
end_typedef

begin_comment
comment|/* 32 bit integer */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|UINT32
typedef|;
end_typedef

begin_comment
comment|/* 32 bit integer (unsigned) */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|ADDR32
typedef|;
end_typedef

begin_comment
comment|/* 32 bit address */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|INST32
typedef|;
end_typedef

begin_comment
comment|/* 32 bit instruction */
end_comment

begin_typedef
typedef|typedef
name|long
name|int
name|BOOLEAN
typedef|;
end_typedef

begin_comment
comment|/* Boolean value (32 bit) */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BYTE
typedef|;
end_typedef

begin_comment
comment|/* byte (8 bit) */
end_comment

begin_typedef
typedef|typedef
name|short
name|int
name|INT16
typedef|;
end_typedef

begin_comment
comment|/* 16 bit integer */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|int
name|UINT16
typedef|;
end_typedef

begin_comment
comment|/* 16 bit integer (unsigned) */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/************************* Message Information ******************************/
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  * Error codes   */
end_comment

begin_comment
comment|/* General errors */
end_comment

begin_define
define|#
directive|define
name|EMUSAGE
value|1
end_define

begin_comment
comment|/* Bad args / flags               */
end_comment

begin_define
define|#
directive|define
name|EMFAIL
value|2
end_define

begin_comment
comment|/* Unrecoverable error            */
end_comment

begin_define
define|#
directive|define
name|EMBADADDR
value|3
end_define

begin_comment
comment|/* Illegal address                */
end_comment

begin_define
define|#
directive|define
name|EMBADREG
value|4
end_define

begin_comment
comment|/* Illegal register               */
end_comment

begin_define
define|#
directive|define
name|EMSYNTAX
value|5
end_define

begin_comment
comment|/* Illegal command syntax         */
end_comment

begin_define
define|#
directive|define
name|EMACCESS
value|6
end_define

begin_comment
comment|/* Could not access memory        */
end_comment

begin_define
define|#
directive|define
name|EMALLOC
value|7
end_define

begin_comment
comment|/* Could not allocate memory      */
end_comment

begin_define
define|#
directive|define
name|EMTARGET
value|8
end_define

begin_comment
comment|/* Unknown target type            */
end_comment

begin_define
define|#
directive|define
name|EMHINIT
value|9
end_define

begin_comment
comment|/* Could not initialize host      */
end_comment

begin_define
define|#
directive|define
name|EMCOMM
value|10
end_define

begin_comment
comment|/* Could not open communication channel */
end_comment

begin_comment
comment|/* Message errors */
end_comment

begin_define
define|#
directive|define
name|EMBADMSG
value|11
end_define

begin_comment
comment|/* Unknown message type           */
end_comment

begin_define
define|#
directive|define
name|EMMSG2BIG
value|12
end_define

begin_comment
comment|/* Message to large for buffer    */
end_comment

begin_define
define|#
directive|define
name|EMNOSEND
value|13
end_define

begin_comment
comment|/* Could not send message         */
end_comment

begin_define
define|#
directive|define
name|EMNORECV
value|14
end_define

begin_comment
comment|/* Could not receive message      */
end_comment

begin_define
define|#
directive|define
name|EMRESET
value|15
end_define

begin_comment
comment|/* Could not RESET target         */
end_comment

begin_define
define|#
directive|define
name|EMCONFIG
value|16
end_define

begin_comment
comment|/* Could not get target CONFIG    */
end_comment

begin_define
define|#
directive|define
name|EMSTATUS
value|17
end_define

begin_comment
comment|/* Could not get target STATUS    */
end_comment

begin_define
define|#
directive|define
name|EMREAD
value|18
end_define

begin_comment
comment|/* Could not READ target memory   */
end_comment

begin_define
define|#
directive|define
name|EMWRITE
value|19
end_define

begin_comment
comment|/* Could not WRITE target memory  */
end_comment

begin_define
define|#
directive|define
name|EMBKPTSET
value|20
end_define

begin_comment
comment|/* Could not set breakpoint       */
end_comment

begin_define
define|#
directive|define
name|EMBKPTRM
value|21
end_define

begin_comment
comment|/* Could not remove breakpoint    */
end_comment

begin_define
define|#
directive|define
name|EMBKPTSTAT
value|22
end_define

begin_comment
comment|/* Could not get breakpoint status */
end_comment

begin_define
define|#
directive|define
name|EMBKPTNONE
value|23
end_define

begin_comment
comment|/* All breakpoints in use         */
end_comment

begin_define
define|#
directive|define
name|EMBKPTUSED
value|24
end_define

begin_comment
comment|/* Breakpoints already in use     */
end_comment

begin_define
define|#
directive|define
name|EMCOPY
value|25
end_define

begin_comment
comment|/* Could not COPY target memory   */
end_comment

begin_define
define|#
directive|define
name|EMFILL
value|26
end_define

begin_comment
comment|/* Could not FILL target memory   */
end_comment

begin_define
define|#
directive|define
name|EMINIT
value|27
end_define

begin_comment
comment|/* Could not initialize target memory */
end_comment

begin_define
define|#
directive|define
name|EMGO
value|28
end_define

begin_comment
comment|/* Could not start execution      */
end_comment

begin_define
define|#
directive|define
name|EMSTEP
value|29
end_define

begin_comment
comment|/* Could not single step          */
end_comment

begin_define
define|#
directive|define
name|EMBREAK
value|30
end_define

begin_comment
comment|/* Could not BREAK                */
end_comment

begin_define
define|#
directive|define
name|EMHIF
value|31
end_define

begin_comment
comment|/* Could not perform HIF service  */
end_comment

begin_define
define|#
directive|define
name|EMCHANNEL0
value|32
end_define

begin_comment
comment|/* Could not read CHANNEL0        */
end_comment

begin_define
define|#
directive|define
name|EMCHANNEL1
value|33
end_define

begin_comment
comment|/* Could not write CHANNEL1       */
end_comment

begin_comment
comment|/* COFF file loader errors */
end_comment

begin_define
define|#
directive|define
name|EMOPEN
value|34
end_define

begin_comment
comment|/* Could not open COFF file       */
end_comment

begin_define
define|#
directive|define
name|EMHDR
value|35
end_define

begin_comment
comment|/* Could not read COFF header     */
end_comment

begin_define
define|#
directive|define
name|EMMAGIC
value|36
end_define

begin_comment
comment|/* Bad magic number               */
end_comment

begin_define
define|#
directive|define
name|EMAOUT
value|37
end_define

begin_comment
comment|/* Could not read COFF a.out header */
end_comment

begin_define
define|#
directive|define
name|EMSCNHDR
value|38
end_define

begin_comment
comment|/* Could not read COFF section header */
end_comment

begin_define
define|#
directive|define
name|EMSCN
value|39
end_define

begin_comment
comment|/* Could not read COFF section    */
end_comment

begin_define
define|#
directive|define
name|EMCLOSE
value|40
end_define

begin_comment
comment|/* Could not close COFF file      */
end_comment

begin_comment
comment|/* Log file errors */
end_comment

begin_define
define|#
directive|define
name|EMLOGOPEN
value|41
end_define

begin_comment
comment|/* Could not open log file        */
end_comment

begin_define
define|#
directive|define
name|EMLOGREAD
value|42
end_define

begin_comment
comment|/* Could not read log file        */
end_comment

begin_define
define|#
directive|define
name|EMLOGWRITE
value|43
end_define

begin_comment
comment|/* Could not write to log file    */
end_comment

begin_define
define|#
directive|define
name|EMLOGCLOSE
value|44
end_define

begin_comment
comment|/* Could not close log file       */
end_comment

begin_comment
comment|/* Command file errors */
end_comment

begin_define
define|#
directive|define
name|EMCMDOPEN
value|45
end_define

begin_comment
comment|/* Could not open command file    */
end_comment

begin_define
define|#
directive|define
name|EMCMDREAD
value|46
end_define

begin_comment
comment|/* Could not read command file    */
end_comment

begin_define
define|#
directive|define
name|EMCMDWRITE
value|47
end_define

begin_comment
comment|/* Could not write to command file */
end_comment

begin_define
define|#
directive|define
name|EMCMDCLOSE
value|48
end_define

begin_comment
comment|/* Could not close comand file    */
end_comment

begin_define
define|#
directive|define
name|EMTIMEOUT
value|49
end_define

begin_comment
comment|/* Host timed out waiting for a message */
end_comment

begin_define
define|#
directive|define
name|EMCOMMTYPE
value|50
end_define

begin_comment
comment|/* A '-t' flag must be specified  */
end_comment

begin_define
define|#
directive|define
name|EMCOMMERR
value|51
end_define

begin_comment
comment|/* Communication error            */
end_comment

begin_define
define|#
directive|define
name|EMBAUD
value|52
end_define

begin_comment
comment|/* Invalid baud rate specified    */
end_comment

begin_comment
comment|/*  * Memory Spaces  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_REG
value|0
end_define

begin_comment
comment|/* Local processor register     */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_REG
value|1
end_define

begin_comment
comment|/* Global processor register    */
end_comment

begin_define
define|#
directive|define
name|SPECIAL_REG
value|2
end_define

begin_comment
comment|/* Special processor register   */
end_comment

begin_define
define|#
directive|define
name|TLB_REG
value|3
end_define

begin_comment
comment|/* Translation Lookaside Buffer */
end_comment

begin_define
define|#
directive|define
name|COPROC_REG
value|4
end_define

begin_comment
comment|/* Coprocessor register         */
end_comment

begin_define
define|#
directive|define
name|I_MEM
value|5
end_define

begin_comment
comment|/* Instruction Memory           */
end_comment

begin_define
define|#
directive|define
name|D_MEM
value|6
end_define

begin_comment
comment|/* Data Memory                  */
end_comment

begin_define
define|#
directive|define
name|I_ROM
value|7
end_define

begin_comment
comment|/* Instruction ROM              */
end_comment

begin_define
define|#
directive|define
name|D_ROM
value|8
end_define

begin_comment
comment|/* Data ROM                     */
end_comment

begin_define
define|#
directive|define
name|I_O
value|9
end_define

begin_comment
comment|/* Input/Output                 */
end_comment

begin_define
define|#
directive|define
name|I_CACHE
value|10
end_define

begin_comment
comment|/* Instruction Cache            */
end_comment

begin_define
define|#
directive|define
name|D_CACHE
value|11
end_define

begin_comment
comment|/* Data Cache                   */
end_comment

begin_comment
comment|/* To supress warnings for zero length array definitions */
end_comment

begin_define
define|#
directive|define
name|DUMMY
value|1
end_define

begin_comment
comment|/* ** Host to target definitions */
end_comment

begin_define
define|#
directive|define
name|RESET
value|0
end_define

begin_define
define|#
directive|define
name|CONFIG_REQ
value|1
end_define

begin_define
define|#
directive|define
name|STATUS_REQ
value|2
end_define

begin_define
define|#
directive|define
name|READ_REQ
value|3
end_define

begin_define
define|#
directive|define
name|WRITE_REQ
value|4
end_define

begin_define
define|#
directive|define
name|BKPT_SET
value|5
end_define

begin_define
define|#
directive|define
name|BKPT_RM
value|6
end_define

begin_define
define|#
directive|define
name|BKPT_STAT
value|7
end_define

begin_define
define|#
directive|define
name|COPY
value|8
end_define

begin_define
define|#
directive|define
name|FILL
value|9
end_define

begin_define
define|#
directive|define
name|INIT
value|10
end_define

begin_define
define|#
directive|define
name|GO
value|11
end_define

begin_define
define|#
directive|define
name|STEP
value|12
end_define

begin_define
define|#
directive|define
name|BREAK
value|13
end_define

begin_define
define|#
directive|define
name|HIF_CALL_RTN
value|64
end_define

begin_define
define|#
directive|define
name|CHANNEL0
value|65
end_define

begin_define
define|#
directive|define
name|CHANNEL1_ACK
value|66
end_define

begin_comment
comment|/* ** Target to host definitions */
end_comment

begin_define
define|#
directive|define
name|RESET_ACK
value|32
end_define

begin_define
define|#
directive|define
name|CONFIG
value|33
end_define

begin_define
define|#
directive|define
name|STATUS
value|34
end_define

begin_define
define|#
directive|define
name|READ_ACK
value|35
end_define

begin_define
define|#
directive|define
name|WRITE_ACK
value|36
end_define

begin_define
define|#
directive|define
name|BKPT_SET_ACK
value|37
end_define

begin_define
define|#
directive|define
name|BKPT_RM_ACK
value|38
end_define

begin_define
define|#
directive|define
name|BKPT_STAT_ACK
value|39
end_define

begin_define
define|#
directive|define
name|COPY_ACK
value|40
end_define

begin_define
define|#
directive|define
name|FILL_ACK
value|41
end_define

begin_define
define|#
directive|define
name|INIT_ACK
value|42
end_define

begin_define
define|#
directive|define
name|HALT
value|43
end_define

begin_define
define|#
directive|define
name|ERROR
value|63
end_define

begin_define
define|#
directive|define
name|HIF_CALL
value|96
end_define

begin_define
define|#
directive|define
name|CHANNEL0_ACK
value|97
end_define

begin_define
define|#
directive|define
name|CHANNEL1
value|98
end_define

begin_comment
comment|/* A "generic" message */
end_comment

begin_struct
struct|struct
name|generic_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* generic */
name|INT32
name|length
decl_stmt|;
name|BYTE
name|byte
index|[
name|DUMMY
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A "generic" message (with an INT32 array) */
end_comment

begin_struct
struct|struct
name|generic_int32_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* generic */
name|INT32
name|length
decl_stmt|;
name|INT32
name|int32
index|[
name|DUMMY
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ** Host to target messages */
end_comment

begin_struct
struct|struct
name|reset_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 0 */
name|INT32
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|config_req_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 1 */
name|INT32
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|status_req_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 2 */
name|INT32
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|read_req_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 3 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|address
decl_stmt|;
name|INT32
name|byte_count
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|write_req_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 4 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|address
decl_stmt|;
name|INT32
name|byte_count
decl_stmt|;
name|BYTE
name|data
index|[
name|DUMMY
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|write_r_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 4 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|address
decl_stmt|;
name|INT32
name|byte_count
decl_stmt|;
name|INT32
name|data
index|[
name|DUMMY
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bkpt_set_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 5 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|bkpt_addr
decl_stmt|;
name|INT32
name|pass_count
decl_stmt|;
name|INT32
name|bkpt_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bkpt_rm_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 6 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|bkpt_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bkpt_stat_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 7 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|bkpt_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|copy_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 8 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|source_space
decl_stmt|;
name|ADDR32
name|source_addr
decl_stmt|;
name|INT32
name|dest_space
decl_stmt|;
name|ADDR32
name|dest_addr
decl_stmt|;
name|INT32
name|byte_count
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fill_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 9 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|start_addr
decl_stmt|;
name|INT32
name|fill_count
decl_stmt|;
name|INT32
name|byte_count
decl_stmt|;
name|BYTE
name|fill_data
index|[
name|DUMMY
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|init_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 10 */
name|INT32
name|length
decl_stmt|;
name|ADDR32
name|text_start
decl_stmt|;
name|ADDR32
name|text_end
decl_stmt|;
name|ADDR32
name|data_start
decl_stmt|;
name|ADDR32
name|data_end
decl_stmt|;
name|ADDR32
name|entry_point
decl_stmt|;
name|INT32
name|mem_stack_size
decl_stmt|;
name|INT32
name|reg_stack_size
decl_stmt|;
name|ADDR32
name|arg_start
decl_stmt|;
name|INT32
name|os_control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|go_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 11 */
name|INT32
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|step_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 12 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|break_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 13 */
name|INT32
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hif_call_rtn_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 64 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|service_number
decl_stmt|;
name|INT32
name|gr121
decl_stmt|;
name|INT32
name|gr96
decl_stmt|;
name|INT32
name|gr97
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|channel0_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 65 */
name|INT32
name|length
decl_stmt|;
name|BYTE
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|channel1_ack_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 66 */
name|INT32
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ** Target to host messages */
end_comment

begin_struct
struct|struct
name|reset_ack_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 32 */
name|INT32
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|config_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 33 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|processor_id
decl_stmt|;
name|INT32
name|version
decl_stmt|;
name|ADDR32
name|I_mem_start
decl_stmt|;
name|INT32
name|I_mem_size
decl_stmt|;
name|ADDR32
name|D_mem_start
decl_stmt|;
name|INT32
name|D_mem_size
decl_stmt|;
name|ADDR32
name|ROM_start
decl_stmt|;
name|INT32
name|ROM_size
decl_stmt|;
name|INT32
name|max_msg_size
decl_stmt|;
name|INT32
name|max_bkpts
decl_stmt|;
name|INT32
name|coprocessor
decl_stmt|;
name|INT32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|status_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 34 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|msgs_sent
decl_stmt|;
name|INT32
name|msgs_received
decl_stmt|;
name|INT32
name|errors
decl_stmt|;
name|INT32
name|bkpts_hit
decl_stmt|;
name|INT32
name|bkpts_free
decl_stmt|;
name|INT32
name|traps
decl_stmt|;
name|INT32
name|fills
decl_stmt|;
name|INT32
name|spills
decl_stmt|;
name|INT32
name|cycles
decl_stmt|;
name|INT32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|read_ack_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 35 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|address
decl_stmt|;
name|INT32
name|byte_count
decl_stmt|;
name|BYTE
name|data
index|[
name|DUMMY
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|read_r_ack_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 35 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|address
decl_stmt|;
name|INT32
name|byte_count
decl_stmt|;
name|INT32
name|data
index|[
name|DUMMY
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|write_ack_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 36 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|address
decl_stmt|;
name|INT32
name|byte_count
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bkpt_set_ack_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 37 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|address
decl_stmt|;
name|INT32
name|pass_count
decl_stmt|;
name|INT32
name|bkpt_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bkpt_rm_ack_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 38 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|address
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bkpt_stat_ack_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 39 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|address
decl_stmt|;
name|INT32
name|pass_count
decl_stmt|;
name|INT32
name|bkpt_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|copy_ack_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 40 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|source_space
decl_stmt|;
name|ADDR32
name|source_addr
decl_stmt|;
name|INT32
name|dest_space
decl_stmt|;
name|ADDR32
name|dest_addr
decl_stmt|;
name|INT32
name|byte_count
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fill_ack_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 41 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|start_addr
decl_stmt|;
name|INT32
name|fill_count
decl_stmt|;
name|INT32
name|byte_count
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|init_ack_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 42 */
name|INT32
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|halt_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 43 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|pc0
decl_stmt|;
name|ADDR32
name|pc1
decl_stmt|;
name|INT32
name|trap_number
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|error_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 63 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|error_code
decl_stmt|;
name|INT32
name|memory_space
decl_stmt|;
name|ADDR32
name|address
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hif_call_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 96 */
name|INT32
name|length
decl_stmt|;
name|INT32
name|service_number
decl_stmt|;
name|INT32
name|lr2
decl_stmt|;
name|INT32
name|lr3
decl_stmt|;
name|INT32
name|lr4
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|channel0_ack_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 97 */
name|INT32
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|channel1_msg_t
block|{
name|INT32
name|code
decl_stmt|;
comment|/* 98 */
name|INT32
name|length
decl_stmt|;
name|BYTE
name|data
index|[
name|DUMMY
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ** Union all of the message types together */
end_comment

begin_union
union|union
name|msg_t
block|{
name|struct
name|generic_msg_t
name|generic_msg
decl_stmt|;
name|struct
name|generic_int32_msg_t
name|generic_int32_msg
decl_stmt|;
name|struct
name|reset_msg_t
name|reset_msg
decl_stmt|;
name|struct
name|config_req_msg_t
name|config_req_msg
decl_stmt|;
name|struct
name|status_req_msg_t
name|status_req_msg
decl_stmt|;
name|struct
name|read_req_msg_t
name|read_req_msg
decl_stmt|;
name|struct
name|write_req_msg_t
name|write_req_msg
decl_stmt|;
name|struct
name|write_r_msg_t
name|write_r_msg
decl_stmt|;
name|struct
name|bkpt_set_msg_t
name|bkpt_set_msg
decl_stmt|;
name|struct
name|bkpt_rm_msg_t
name|bkpt_rm_msg
decl_stmt|;
name|struct
name|bkpt_stat_msg_t
name|bkpt_stat_msg
decl_stmt|;
name|struct
name|copy_msg_t
name|copy_msg
decl_stmt|;
name|struct
name|fill_msg_t
name|fill_msg
decl_stmt|;
name|struct
name|init_msg_t
name|init_msg
decl_stmt|;
name|struct
name|go_msg_t
name|go_msg
decl_stmt|;
name|struct
name|step_msg_t
name|step_msg
decl_stmt|;
name|struct
name|break_msg_t
name|break_msg
decl_stmt|;
name|struct
name|hif_call_rtn_msg_t
name|hif_call_rtn_msg
decl_stmt|;
name|struct
name|channel0_msg_t
name|channel0_msg
decl_stmt|;
name|struct
name|channel1_ack_msg_t
name|channel1_ack_msg
decl_stmt|;
name|struct
name|reset_ack_msg_t
name|reset_ack_msg
decl_stmt|;
name|struct
name|config_msg_t
name|config_msg
decl_stmt|;
name|struct
name|status_msg_t
name|status_msg
decl_stmt|;
name|struct
name|read_ack_msg_t
name|read_ack_msg
decl_stmt|;
name|struct
name|read_r_ack_msg_t
name|read_r_ack_msg
decl_stmt|;
name|struct
name|write_ack_msg_t
name|write_ack_msg
decl_stmt|;
name|struct
name|bkpt_set_ack_msg_t
name|bkpt_set_ack_msg
decl_stmt|;
name|struct
name|bkpt_rm_ack_msg_t
name|bkpt_rm_ack_msg
decl_stmt|;
name|struct
name|bkpt_stat_ack_msg_t
name|bkpt_stat_ack_msg
decl_stmt|;
name|struct
name|copy_ack_msg_t
name|copy_ack_msg
decl_stmt|;
name|struct
name|fill_ack_msg_t
name|fill_ack_msg
decl_stmt|;
name|struct
name|init_ack_msg_t
name|init_ack_msg
decl_stmt|;
name|struct
name|halt_msg_t
name|halt_msg
decl_stmt|;
name|struct
name|error_msg_t
name|error_msg
decl_stmt|;
name|struct
name|hif_call_msg_t
name|hif_call_msg
decl_stmt|;
name|struct
name|channel0_ack_msg_t
name|channel0_ack_msg
decl_stmt|;
name|struct
name|channel1_msg_t
name|channel1_msg
decl_stmt|;
block|}
union|;
end_union

end_unit

