begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by Julian Elischer (julian@tfs.com)  * for TRW Financial Systems for use under the MACH(2.5) operating system.  *  * TRW Financial Systems, in accordance with their agreement with Carnegie  * Mellon University, makes this software available to CMU to distribute  * or use in any manner that they see fit as long as this message is kept with  * the software. For this reason TFS also grants any other persons or  * organisations permission to use or modify this software.  *  * TFS supplies this software to be publicly redistributed  * on the understanding that TFS is not responsible for the correct  * functioning of this software in any circumstances.  *  * PATCHES MAGIC                LEVEL   PATCH THAT GOT US HERE  * --------------------         -----   ----------------------  * CURRENT PATCH LEVEL:         1       00098  * --------------------         -----   ----------------------  *  * 16 Feb 93	Julian Elischer		ADDED for SCSI system  *  */
end_comment

begin_comment
comment|/*  * Ported to run under 386BSD by Julian Elischer (julian@tfs.com) Sept 1992  */
end_comment

begin_comment
comment|/***********************************************\ * these calls are called by the high-end	* * drivers to get services from whatever low-end	* * drivers they are attached to			* \***********************************************/
end_comment

begin_struct
struct|struct
name|scsi_switch
block|{
name|int
function_decl|(
modifier|*
name|scsi_cmd
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|scsi_minphys
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|open_target_lu
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|close_target_lu
function_decl|)
parameter_list|()
function_decl|;
name|long
name|int
function_decl|(
modifier|*
name|adapter_info
function_decl|)
parameter_list|()
function_decl|;
comment|/* see definitions below */
name|u_long
name|spare
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AD_INF_MAX_CMDS
value|0x000000FF
end_define

begin_comment
comment|/* maximum number of entries 						queuable to a device by  						the adapter */
end_comment

begin_comment
comment|/* 24 bits of other adapter charcteristics go here */
end_comment

begin_comment
comment|/***********************************************\ * The scsi debug control bits			* \***********************************************/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|scsi_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PRINTROUTINES
value|0x01
end_define

begin_define
define|#
directive|define
name|TRACEOPENS
value|0x02
end_define

begin_define
define|#
directive|define
name|TRACEINTERRUPTS
value|0x04
end_define

begin_define
define|#
directive|define
name|SHOWREQUESTS
value|0x08
end_define

begin_define
define|#
directive|define
name|SHOWSCATGATH
value|0x10
end_define

begin_define
define|#
directive|define
name|SHOWINQUIRY
value|0x20
end_define

begin_define
define|#
directive|define
name|SHOWCOMMANDS
value|0x40
end_define

begin_comment
comment|/********************************/
end_comment

begin_comment
comment|/* return values for scsi_cmd() */
end_comment

begin_comment
comment|/********************************/
end_comment

begin_define
define|#
directive|define
name|SUCCESSFULLY_QUEUED
value|0
end_define

begin_define
define|#
directive|define
name|TRY_AGAIN_LATER
value|1
end_define

begin_define
define|#
directive|define
name|COMPLETE
value|2
end_define

begin_define
define|#
directive|define
name|HAD_ERROR
value|3
end_define

begin_struct
struct|struct
name|scsi_xfer
block|{
name|struct
name|scsi_xfer
modifier|*
name|next
decl_stmt|;
comment|/* when free */
name|int
name|flags
decl_stmt|;
name|u_char
name|adapter
decl_stmt|;
name|u_char
name|targ
decl_stmt|;
name|u_char
name|lu
decl_stmt|;
name|u_char
name|retries
decl_stmt|;
comment|/* the number of times to retry */
name|long
name|int
name|timeout
decl_stmt|;
comment|/* in miliseconds */
name|struct
name|scsi_generic
modifier|*
name|cmd
decl_stmt|;
name|int
name|cmdlen
decl_stmt|;
name|u_char
modifier|*
name|data
decl_stmt|;
comment|/* either the dma address OR a uio address */
name|int
name|datalen
decl_stmt|;
comment|/* data len (blank if uio)    */
name|int
name|resid
decl_stmt|;
name|int
function_decl|(
modifier|*
name|when_done
function_decl|)
parameter_list|()
function_decl|;
name|int
name|done_arg
decl_stmt|;
name|int
name|done_arg2
decl_stmt|;
name|int
name|error
decl_stmt|;
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
name|struct
name|scsi_sense_data
name|sense
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/********************************/
end_comment

begin_comment
comment|/* Flag values			*/
end_comment

begin_comment
comment|/********************************/
end_comment

begin_define
define|#
directive|define
name|SCSI_NOSLEEP
value|0x01
end_define

begin_comment
comment|/* Not a user... don't sleep		*/
end_comment

begin_define
define|#
directive|define
name|SCSI_NOMASK
value|0x02
end_define

begin_comment
comment|/* dont allow interrupts.. booting	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_NOSTART
value|0x04
end_define

begin_comment
comment|/* left over from ancient history	*/
end_comment

begin_define
define|#
directive|define
name|ITSDONE
value|0x10
end_define

begin_comment
comment|/* the transfer is as done as it gets	*/
end_comment

begin_define
define|#
directive|define
name|INUSE
value|0x20
end_define

begin_comment
comment|/* The scsi_xfer block is in use	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_SILENT
value|0x40
end_define

begin_comment
comment|/* Don't report errors to console	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_ERR_OK
value|0x80
end_define

begin_comment
comment|/* An error on this operation is OK.	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_RESET
value|0x100
end_define

begin_comment
comment|/* Reset the device in question		*/
end_comment

begin_define
define|#
directive|define
name|SCSI_DATA_UIO
value|0x200
end_define

begin_comment
comment|/* The data address refers to a UIO	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_DATA_IN
value|0x400
end_define

begin_comment
comment|/* expect data to come INTO memory	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_DATA_OUT
value|0x800
end_define

begin_comment
comment|/* expect data to flow OUT of memory	*/
end_comment

begin_define
define|#
directive|define
name|SCSI_TARGET
value|0x1000
end_define

begin_comment
comment|/* This defines a TARGET mode op.	*/
end_comment

begin_comment
comment|/********************************/
end_comment

begin_comment
comment|/* Error values			*/
end_comment

begin_comment
comment|/********************************/
end_comment

begin_define
define|#
directive|define
name|XS_NOERROR
value|0x0
end_define

begin_comment
comment|/* there is no error, (sense is invalid)  */
end_comment

begin_define
define|#
directive|define
name|XS_SENSE
value|0x1
end_define

begin_comment
comment|/* Check the returned sense for the error */
end_comment

begin_define
define|#
directive|define
name|XS_DRIVER_STUFFUP
value|0x2
end_define

begin_comment
comment|/* Driver failed to perform operation	  */
end_comment

begin_define
define|#
directive|define
name|XS_TIMEOUT
value|0x03
end_define

begin_comment
comment|/* The device timed out.. turned off?	  */
end_comment

begin_define
define|#
directive|define
name|XS_SWTIMEOUT
value|0x04
end_define

begin_comment
comment|/* The Timeout reported was caught by SW  */
end_comment

begin_define
define|#
directive|define
name|XS_BUSY
value|0x08
end_define

begin_comment
comment|/* The device busy, try again later?	  */
end_comment

end_unit

