begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Qlogic ISP Host Adapter Public Target Interface Structures&& Routines  *---------------------------------------  * Copyright (c) 2000 by Matthew Jacob  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * Matthew Jacob  * Feral Software  * mjacob@feral.com  */
end_comment

begin_comment
comment|/*  * Required software target mode message and event handling structures.  *  * The message and event structures are used by the MI layer  * to propagate messages and events upstream.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN_MSGLEN
end_ifndef

begin_define
define|#
directive|define
name|IN_MSGLEN
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|nt_hba
decl_stmt|;
comment|/* HBA tag */
name|u_int64_t
name|nt_iid
decl_stmt|;
comment|/* inititator id */
name|u_int64_t
name|nt_tgt
decl_stmt|;
comment|/* target id */
name|u_int64_t
name|nt_lun
decl_stmt|;
comment|/* logical unit */
name|u_int8_t
name|nt_bus
decl_stmt|;
comment|/* bus */
name|u_int8_t
name|nt_tagtype
decl_stmt|;
comment|/* tag type */
name|u_int16_t
name|nt_tagval
decl_stmt|;
comment|/* tag value */
name|u_int8_t
name|nt_msg
index|[
name|IN_MSGLEN
index|]
decl_stmt|;
comment|/* message content */
block|}
name|tmd_msg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|ev_hba
decl_stmt|;
comment|/* HBA tag */
name|u_int16_t
name|ev_bus
decl_stmt|;
comment|/* bus */
name|u_int16_t
name|ev_event
decl_stmt|;
comment|/* type of async event */
block|}
name|tmd_event_t
typedef|;
end_typedef

begin_comment
comment|/*  * Suggested Software Target Mode Command Handling structure.  *  * A note about terminology:  *  *   MD stands for "Machine Dependent".  *  *    This driver is structured in three layers: Outer MD, core, and inner MD.  *    The latter also is bus dependent (i.e., is cognizant of PCI bus issues  *    as well as platform issues).  *  *  *   "Outer Layer" means "Other Module"  *  *    Some additional module that actually implements SCSI target command  *    policy is the recipient of incoming commands and the source of the  *    disposition for them.  *  * The command structure below is one suggested possible MD command structure,  * but since the handling of thbis is entirely in the MD layer, there is  * no explicit or implicit requirement that it be used.  *  * The cd_private tag should be used by the MD layer to keep a free list  * of these structures. Code outside of this driver can then use this  * as an to identify it's own unit structures. That is, when not on the MD  * layer's freelist, the MD layer should shove into it the identifier  * that the outer layer has for it- passed in on an initial QIN_HBA_REG  * call (see below).  *  * The cd_hba tag is a tag that uniquely identifies the HBA this target  * mode command is coming from. The outer layer has to pass this back  * unchanged to avoid chaos.  *  * The cd_iid, cd_tgt, cd_lun and cd_bus tags are used to identify the  * id of the initiator who sent us a command, the target claim to be, the  * lun on the target we claim to be, and the bus instance (for multiple  * bus host adapters) that this applies to (consider it an extra Port  * parameter). The iid, tgt and lun values are deliberately chosen to be  * fat so that, for example, World Wide Names can be used instead of  * the units that the Qlogic firmware uses (in the case where the MD  * layer maintains a port database, for example).  *  * The cd_tagtype field specifies what kind of command tag has been  * sent with the command. The cd_tagval is the tag's value (low 16  * bits). It also contains (in the upper 16 bits) any command handle.  *  *  * N.B.: when the MD layer sends this command to outside software  * the outside software likely *MUST* return the same cd_tagval that  * was in place because this value is likely what the Qlogic f/w uses  * to identify a command.  *  * The cd_cdb contains storage for the passed in command descriptor block.  * This is the maximum size we can get out of the Qlogic f/w. There's no  * passed in length because whoever decodes the command to act upon it  * will know what the appropriate length is.  *  * The tag cd_lflags are the flags set by the MD driver when it gets  * command incoming or when it needs to inform any outside entities  * that the last requested action failed.  *  * The tag cd_hflags should be set by any outside software to indicate  * the validity of sense and status fields (defined below) and to indicate  * the direction data is expected to move. It is an error to have both  * CDFH_DATA_IN and CDFH_DATA_OUT set.  *  * If the CDFH_STSVALID flag is set, the command should be completed (after  * sending any data and/or status). If CDFH_SNSVALID is set and the MD layer  * can also handle sending the associated sense data (either back with an  * FCP RESPONSE IU for Fibre Channel or otherwise automatically handling a  * REQUEST SENSE from the initator for this target/lun), the MD layer will  * set the CDFL_SENTSENSE flag on successful transmission of the sense data.  * It is an error for the CDFH_SNSVALID bit to be set and CDFH_STSVALID not  * to be set. It is an error for the CDFH_SNSVALID be set and the associated  * SCSI status (cd_scsi_status) not be set to CHECK CONDITON.  *   * The tag cd_data points to a data segment to either be filled or  * read from depending on the direction of data movement. The tag  * is undefined if no data direction is set. The MD layer and outer  * layers must agree on the meaning of cd_data.  *  * The tag cd_totlen is the total data amount expected to be moved  * over the life of the command. It *may* be set by the MD layer, possibly  * from the datalen field of an FCP CMND IU unit. If it shows up in the outer  * layers set to zero and the CDB indicates data should be moved, the outer  * layer should set it to the amount expected to be moved.  *  * The tag cd_resid should be the total residual of data not transferred.  * The outer layers need to set this at the begining of command processing  * to equal cd_totlen. As data is successfully moved, this value is decreased.  * At the end of a command, any nonzero residual indicates the number of bytes  * requested but not moved. XXXXXXXXXXXXXXXXXXXXXXX TOO VAGUE!!!   *  * The tag cd_xfrlen is the length of the currently active data transfer.  * This allows several interations between any outside software and the  * MD layer to move data.  *  * The reason that total length and total residual have to be tracked  * is that fibre channel FCP DATA IU units have to have a relative  * offset field.  *  * N.B.: there is no necessary 1-to-1 correspondence between any one  * data transfer segment and the number of CTIOs that will be generated  * satisfy the current data transfer segment. It's not also possible to  * predict how big a transfer can be before it will be 'too big'. Be  * reasonable- a 64KB transfer is 'reasonable'. A 1MB transfer may not  * be. A 32MB transfer is unreasonable. The problem here has to do with  * how CTIOs can be used to map passed data pointers. In systems which  * have page based scatter-gather requirements, each PAGESIZEd chunk will  * consume one data segment descriptor- you get 3 or 4 of them per CTIO.  * The size of the REQUEST QUEUE you drop a CTIO onto is finite (typically  * it's 256, but on some systems it's even smaller, and note you have to  * sure this queue with the initiator side of this driver).  *  * The tags cd_sense and cd_scsi_status are pretty obvious.  *  * The tag cd_error is to communicate between the MD layer and outer software  * the current error conditions.  *  * The tag cd_reserved pads out the structure to 128 bytes. The first  * half of the pad area is reserved to the MD layer, and the second half  * may be used by outer layers, for scratch purposes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LP64
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparcv9cpu
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc_v9__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_LP64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_TMD_PAD_LEN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_LP64
end_ifdef

begin_define
define|#
directive|define
name|_TMD_PAD_LEN
value|12
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_TMD_PAD_LEN
value|24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ATIO_CDBLEN
end_ifndef

begin_define
define|#
directive|define
name|ATIO_CDBLEN
value|26
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|QLTM_SENSELEN
end_ifndef

begin_define
define|#
directive|define
name|QLTM_SENSELEN
value|18
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|tmd_cmd
block|{
name|void
modifier|*
name|cd_private
decl_stmt|;
comment|/* layer private data */
name|void
modifier|*
name|cd_hba
decl_stmt|;
comment|/* HBA tag */
name|void
modifier|*
name|cd_data
decl_stmt|;
comment|/* 'pointer' to data */
name|u_int64_t
name|cd_iid
decl_stmt|;
comment|/* initiator ID */
name|u_int64_t
name|cd_tgt
decl_stmt|;
comment|/* target id */
name|u_int64_t
name|cd_lun
decl_stmt|;
comment|/* logical unit */
name|u_int8_t
name|cd_bus
decl_stmt|;
comment|/* bus */
name|u_int8_t
name|cd_tagtype
decl_stmt|;
comment|/* tag type */
name|u_int32_t
name|cd_tagval
decl_stmt|;
comment|/* tag value */
name|u_int8_t
name|cd_cdb
index|[
name|ATIO_CDBLEN
index|]
decl_stmt|;
comment|/* Command */
name|u_int8_t
name|cd_lflags
decl_stmt|;
comment|/* flags lower level sets */
name|u_int8_t
name|cd_hflags
decl_stmt|;
comment|/* flags higher level sets */
name|u_int32_t
name|cd_totlen
decl_stmt|;
comment|/* total data requirement */
name|u_int32_t
name|cd_resid
decl_stmt|;
comment|/* total data residual */
name|u_int32_t
name|cd_xfrlen
decl_stmt|;
comment|/* current data requirement */
name|int32_t
name|cd_error
decl_stmt|;
comment|/* current error */
name|u_int8_t
name|cd_sense
index|[
name|QLTM_SENSELEN
index|]
decl_stmt|;
name|u_int16_t
name|cd_scsi_status
decl_stmt|;
comment|/* closing SCSI status */
name|u_int8_t
name|cd_reserved
index|[
name|_TMD_PAD_LEN
index|]
decl_stmt|;
block|}
name|tmd_cmd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CDFL_SNSVALID
value|0x01
end_define

begin_comment
comment|/* sense data (from f/w) valid */
end_comment

begin_define
define|#
directive|define
name|CDFL_NODISC
value|0x02
end_define

begin_comment
comment|/* disconnects disabled */
end_comment

begin_define
define|#
directive|define
name|CDFL_SENTSENSE
value|0x04
end_define

begin_comment
comment|/* last action sent sense data */
end_comment

begin_define
define|#
directive|define
name|CDFL_SENTSTATUS
value|0x08
end_define

begin_comment
comment|/* last action sent status */
end_comment

begin_define
define|#
directive|define
name|CDFL_ERROR
value|0x10
end_define

begin_comment
comment|/* last action ended in error */
end_comment

begin_define
define|#
directive|define
name|CDFL_BUSY
value|0x40
end_define

begin_comment
comment|/* this command is not on a free list */
end_comment

begin_define
define|#
directive|define
name|CDFL_PRIVATE_0
value|0x80
end_define

begin_comment
comment|/* private layer flags */
end_comment

begin_define
define|#
directive|define
name|CDFH_SNSVALID
value|0x01
end_define

begin_comment
comment|/* sense data valid */
end_comment

begin_define
define|#
directive|define
name|CDFH_STSVALID
value|0x02
end_define

begin_comment
comment|/* status valid */
end_comment

begin_define
define|#
directive|define
name|CDFH_NODATA
value|0x00
end_define

begin_comment
comment|/* no data transfer expected */
end_comment

begin_define
define|#
directive|define
name|CDFH_DATA_IN
value|0x04
end_define

begin_comment
comment|/* target (us) -> initiator (them) */
end_comment

begin_define
define|#
directive|define
name|CDFH_DATA_OUT
value|0x08
end_define

begin_comment
comment|/* initiator (them) -> target (us) */
end_comment

begin_define
define|#
directive|define
name|CDFH_DATA_MASK
value|0x0C
end_define

begin_comment
comment|/* mask to cover data direction */
end_comment

begin_define
define|#
directive|define
name|CDFH_PRIVATE_0
value|0x80
end_define

begin_comment
comment|/* private layer flags */
end_comment

begin_comment
comment|/*  * Action codes set by the Qlogic MD target driver for  * the external layer to figure out what to do with.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|QOUT_HBA_REG
init|=
literal|0
block|,
comment|/* the argument is a pointer to a hba_register_t */
name|QOUT_TMD_START
block|,
comment|/* the argument is a pointer to a tmd_cmd_t */
name|QOUT_TMD_DONE
block|,
comment|/* the argument is a pointer to a tmd_cmd_t */
name|QOUT_TEVENT
block|,
comment|/* the argument is a pointer to a tmd_event_t */
name|QOUT_TMSG
block|,
comment|/* the argument is a pointer to a tmd_msg_t */
name|QOUT_HBA_UNREG
comment|/* the argument is a pointer to a hba_register_t */
block|}
name|tact_e
typedef|;
end_typedef

begin_comment
comment|/*  * Action codes set by the external layer for the  * MD Qlogic driver to figure out what to do with.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|QIN_HBA_REG
init|=
literal|6
block|,
comment|/* the argument is a pointer to a hba_register_t */
name|QIN_ENABLE
block|,
comment|/* the argument is a pointer to a tmd_cmd_t */
name|QIN_DISABLE
block|,
comment|/* the argument is a pointer to a tmd_cmd_t */
name|QIN_TMD_CONT
block|,
comment|/* the argument is a pointer to a tmd_cmd_t */
name|QIN_TMD_FIN
block|,
comment|/* the argument is a pointer to a done tmd_cmd_t */
name|QIN_HBA_UNREG
comment|/* the argument is a pointer to a hba_register_t */
block|}
name|qact_e
typedef|;
end_typedef

begin_comment
comment|/*  * A word about the START/CONT/DONE/FIN dance:  *  *	When the HBA is enabled for receiving commands, one may	show up  *	without notice. When that happens, the Qlogic target mode driver  *	gets a tmd_cmd_t, fills it with the info that just arrived, and  *	calls the outer layer with a QOUT_TMD_START code and pointer to  *	the tmd_cmd_t.  *  *	The outer layer decodes the command, fetches data, prepares stuff,  *	whatever, and starts by passing back the pointer with a QIN_TMD_CONT  *	code which causes the Qlogic target mode driver to generate CTIOs to  *	satisfy whatever action needs to be taken. When those CTIOs complete,  *	the Qlogic target driver sends the pointer to the cmd_tmd_t back with  *	a QOUT_TMD_DONE code. This repeats for as long as necessary.  *  *	The outer layer signals it wants to end the command by settings within  *	the tmd_cmd_t itself. When the final QIN_TMD_CONT is reported completed,  *	the outer layer frees the tmd_cmd_t by sending the pointer to it  *	back with a QIN_TMD_FIN code.  *  *	The graph looks like:  *  *	QOUT_TMD_START -> [ QIN_TMD_CONT -> QOUT_TMD_DONE ] * -> QIN_TMD_FIN.  *  */
end_comment

begin_comment
comment|/*  * A word about ENABLE/DISABLE: the argument is a pointer to an tmd_cmd_t  * with cd_hba, cd_bus, cd_tgt and cd_lun filled out. If an error occurs  * in either enabling or disabling the described lun, cd_lflags is set  * with CDFL_ERROR.  *  * Logical unit zero must be the first enabled and the last disabled.  */
end_comment

begin_comment
comment|/*  * Target handler functions.  * The MD target handler function (the outer layer calls this)  * should be be prototyped like:  *  *	void target_action(qact_e, void *arg)  *  * The outer layer target handler function (the MD layer calls this)  * should be be prototyped like:  *  *	void system_action(tact_e, void *arg)  */
end_comment

begin_comment
comment|/*  * This structure is used to register to other software modules the  * binding of an HBA identifier, driver name and instance and the  * lun width capapbilities of this target driver. It's up to each  * platform to figure out how it wants to do this, but a typical  * sequence would be for the MD layer to find some external module's  * entry point and start by sending a QOUT_HBA_REG with info filled  * in, and the external module to call back with a QIN_HBA_REG that  * passes back the corresponding information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|r_identity
decl_stmt|;
name|char
name|r_name
index|[
literal|8
index|]
decl_stmt|;
name|int
name|r_inst
decl_stmt|;
name|int
name|r_lunwidth
decl_stmt|;
name|int
name|r_buswidth
decl_stmt|;
name|void
function_decl|(
modifier|*
name|r_action
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
name|hba_register_t
typedef|;
end_typedef

end_unit

