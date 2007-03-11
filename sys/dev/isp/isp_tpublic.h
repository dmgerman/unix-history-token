begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Qlogic ISP Host Adapter Public Target Interface Structures&& Routines  *  * Copyright (c) 1997-2006 by Matthew Jacob  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Host Adapter Public Target Interface Structures&& Routines  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISP_TPUBLIC_H
end_ifndef

begin_define
define|#
directive|define
name|_ISP_TPUBLIC_H
value|1
end_define

begin_comment
comment|/*  * Action codes set by the MD target driver for  * the external layer to figure out what to do with.  */
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
name|QOUT_ENABLE
block|,
comment|/* the argument is a pointer to a enadis_t */
name|QOUT_DISABLE
block|,
comment|/* the argument is a pointer to a enadis_t */
name|QOUT_TMD_START
block|,
comment|/* the argument is a pointer to a tmd_cmd_t */
name|QOUT_TMD_DONE
block|,
comment|/* the argument is a pointer to a tmd_cmd_t */
name|QOUT_NOTIFY
block|,
comment|/* the argument is a pointer to a tmd_notify_t */
name|QOUT_HBA_UNREG
comment|/* the argument is a pointer to a hba_register_t */
block|}
name|tact_e
typedef|;
end_typedef

begin_comment
comment|/*  * Action codes set by the external layer for the  * MD driver to figure out what to do with.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|QIN_HBA_REG
init|=
literal|99
block|,
comment|/* the argument is a pointer to a hba_register_t */
name|QIN_GETINFO
block|,
comment|/* the argument is a pointer to a info_t */
name|QIN_SETINFO
block|,
comment|/* the argument is a pointer to a info_t */
name|QIN_ENABLE
block|,
comment|/* the argument is a pointer to a enadis_t */
name|QIN_DISABLE
block|,
comment|/* the argument is a pointer to a enadis_t */
name|QIN_TMD_CONT
block|,
comment|/* the argument is a pointer to a tmd_cmd_t */
name|QIN_TMD_FIN
block|,
comment|/* the argument is a pointer to a tmd_cmd_t */
name|QIN_NOTIFY_ACK
block|,
comment|/* the argument is a pointer to a tmd_notify_t */
name|QIN_HBA_UNREG
block|,
comment|/* the argument is a pointer to a hba_register_t */
block|}
name|qact_e
typedef|;
end_typedef

begin_comment
comment|/*  * This structure is used to register to other software modules the  * binding of an HBA identifier, driver name and instance and the  * lun width capapbilities of this target driver. It's up to each  * platform to figure out how it wants to do this, but a typical  * sequence would be for the MD layer to find some external module's  * entry point and start by sending a QOUT_HBA_REG with info filled  * in, and the external module to call back with a QIN_HBA_REG that  * passes back the corresponding information.  */
end_comment

begin_define
define|#
directive|define
name|QR_VERSION
value|15
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* NB: tags from here to r_version must never change */
name|void
modifier|*
name|r_identity
decl_stmt|;
name|void
function_decl|(
modifier|*
name|r_action
function_decl|)
parameter_list|(
name|qact_e
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
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
name|r_version
decl_stmt|;
name|uint32_t
name|r_locator
decl_stmt|;
name|uint32_t
name|r_nchannels
decl_stmt|;
enum|enum
block|{
name|R_FC
block|,
name|R_SPI
block|}
name|r_type
enum|;
name|void
modifier|*
name|r_private
decl_stmt|;
block|}
name|hba_register_t
typedef|;
end_typedef

begin_comment
comment|/*  * An information structure that is used to get or set per-channel  * transport layer parameters.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|i_identity
decl_stmt|;
enum|enum
block|{
name|I_FC
block|,
name|I_SPI
block|}
name|i_type
enum|;
name|int
name|i_channel
decl_stmt|;
name|int
name|i_error
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint64_t
name|wwnn_nvram
decl_stmt|;
name|uint64_t
name|wwpn_nvram
decl_stmt|;
name|uint64_t
name|wwnn
decl_stmt|;
name|uint64_t
name|wwpn
decl_stmt|;
block|}
name|fc
struct|;
struct|struct
block|{
name|int
name|iid
decl_stmt|;
block|}
name|spi
struct|;
block|}
name|i_id
union|;
block|}
name|info_t
typedef|;
end_typedef

begin_comment
comment|/*  * Notify structure  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NT_ABORT_TASK
init|=
literal|0x1000
block|,
name|NT_ABORT_TASK_SET
block|,
name|NT_CLEAR_ACA
block|,
name|NT_CLEAR_TASK_SET
block|,
name|NT_LUN_RESET
block|,
name|NT_TARGET_RESET
block|,
name|NT_BUS_RESET
block|,
name|NT_LIP_RESET
block|,
name|NT_LINK_UP
block|,
name|NT_LINK_DOWN
block|,
name|NT_LOGOUT
block|,
name|NT_HBA_RESET
block|}
name|tmd_ncode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tmd_notify
block|{
name|void
modifier|*
name|nt_hba
decl_stmt|;
comment|/* HBA tag */
name|uint64_t
name|nt_iid
decl_stmt|;
comment|/* inititator id */
name|uint64_t
name|nt_tgt
decl_stmt|;
comment|/* target id */
name|uint16_t
name|nt_lun
decl_stmt|;
comment|/* logical unit */
name|uint16_t
label|:
literal|15
operator|,
name|nt_need_ack
operator|:
literal|1
expr_stmt|;
comment|/* this notify needs an ACK */
name|uint64_t
name|nt_tagval
decl_stmt|;
comment|/* tag value */
name|uint32_t
name|nt_channel
decl_stmt|;
comment|/* channel id */
name|tmd_ncode_t
name|nt_ncode
decl_stmt|;
comment|/* action */
name|void
modifier|*
name|nt_lreserved
decl_stmt|;
name|void
modifier|*
name|nt_hreserved
decl_stmt|;
block|}
name|tmd_notify_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LUN_ANY
value|0xffff
end_define

begin_define
define|#
directive|define
name|TGT_ANY
value|((uint64_t) -1)
end_define

begin_define
define|#
directive|define
name|INI_ANY
value|((uint64_t) -1)
end_define

begin_define
define|#
directive|define
name|TAG_ANY
value|((uint64_t) 0)
end_define

begin_define
define|#
directive|define
name|MATCH_TMD
parameter_list|(
name|tmd
parameter_list|,
name|iid
parameter_list|,
name|lun
parameter_list|,
name|tag
parameter_list|)
define|\
value|(                                                   \         (tmd)&&                                        \         (iid == INI_ANY || iid == tmd->cd_iid)&&       \         (lun == LUN_ANY || lun == tmd->cd_lun)&&       \         (tag == TAG_ANY || tag == tmd->cd_tagval)       \     )
end_define

begin_comment
comment|/*  * A word about ENABLE/DISABLE: the argument is a pointer to a enadis_t  * with en_hba, en_iid, en_chan, en_tgt and en_lun filled out.  *  * If an error occurs in either enabling or disabling the described lun  * cd_error is set with an appropriate non-zero value.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|en_private
decl_stmt|;
comment|/* for outer layer usage */
name|void
modifier|*
name|en_hba
decl_stmt|;
comment|/* HBA tag */
name|uint64_t
name|en_iid
decl_stmt|;
comment|/* initiator ID */
name|uint64_t
name|en_tgt
decl_stmt|;
comment|/* target id */
name|uint16_t
name|en_lun
decl_stmt|;
comment|/* logical unit */
name|uint16_t
name|en_chan
decl_stmt|;
comment|/* channel on card */
name|int
name|en_error
decl_stmt|;
block|}
name|enadis_t
typedef|;
end_typedef

begin_comment
comment|/*  * Suggested Software Target Mode Command Handling structure.  *  * A note about terminology:  *  *   MD stands for "Machine Dependent".  *  *    This driver is structured in three layers: Outer MD, core, and inner MD.  *    The latter also is bus dependent (i.e., is cognizant of PCI bus issues  *    as well as platform issues).  *  *  *   "Outer Layer" means "Other Module"  *  *    Some additional module that actually implements SCSI target command  *    policy is the recipient of incoming commands and the source of the  *    disposition for them.  *  * The command structure below is one suggested possible MD command structure,  * but since the handling of thbis is entirely in the MD layer, there is  * no explicit or implicit requirement that it be used.  *  * The cd_private tag should be used by the MD layer to keep a free list  * of these structures. Code outside of this driver can then use this  * to identify it's own unit structures. That is, when not on the MD  * layer's freelist, the MD layer should shove into it the identifier  * that the outer layer has for it- passed in on an initial QIN_HBA_REG  * call (see below).  *  * The cd_hba tag is a tag that uniquely identifies the HBA this target  * mode command is coming from. The outer layer has to pass this back  * unchanged to avoid chaos.  *  * The cd_iid, cd_tgt, cd_lun and cd_port tags are used to identify the  * id of the initiator who sent us a command, the target claim to be, the  * lun on the target we claim to be, and the port instance (for multiple  * port host adapters) that this applies to (consider it an extra port  * parameter). The iid, tgt and lun values are deliberately chosen to be  * fat so that, for example, World Wide Names can be used instead of  * the units that the firmware uses (in the case where the MD  * layer maintains a port database, for example).  *  * The cd_tagtype field specifies what kind of command tag type, if  * any, has been sent with the command. Note that the Outer Layer  * still needs to pass the tag handle through unchanged even  * if the tag type is CD_UNTAGGED.  *  * The cd_cdb contains storage for the passed in command descriptor block.  * There is no need to define length as the callee should be able to  * figure this out.  *  * The tag cd_lflags are the flags set by the MD driver when it gets  * command incoming or when it needs to inform any outside entities  * that the last requested action failed.  *  * The tag cd_hflags should be set by any outside software to indicate  * the validity of sense and status fields (defined below) and to indicate  * the direction data is expected to move. It is an error to have both  * CDFH_DATA_IN and CDFH_DATA_OUT set.  *  * If the CDFH_STSVALID flag is set, the command should be completed (after  * sending any data and/or status). If CDFH_SNSVALID is set and the MD layer  * can also handle sending the associated sense data (either back with an  * FCP RESPONSE IU for Fibre Channel or otherwise automatically handling a  * REQUEST SENSE from the initator for this target/lun), the MD layer will  * set the CDFL_SENTSENSE flag on successful transmission of the sense data.  * It is an error for the CDFH_SNSVALID bit to be set and CDFH_STSVALID not  * to be set. It is an error for the CDFH_SNSVALID be set and the associated  * SCSI status (cd_scsi_status) not be set to CHECK CONDITON.  *   * The tag cd_data points to a data segment to either be filled or  * read from depending on the direction of data movement. The tag  * is undefined if no data direction is set. The MD layer and outer  * layers must agree on the meaning of cd_data and it is specifically  * not defined here.  *  * The tag cd_totlen is the total data amount expected to be moved  * over the life of the command. It may be set by the MD layer, possibly  * from the datalen field of an FCP CMND IU unit. If it shows up in the outer  * layers set to zero and the CDB indicates data should be moved, the outer  * layer should set it to the amount expected to be moved.  *  * The tag cd_resid should be the total residual of data not transferred.  * The outer layers need to set this at the begining of command processing  * to equal cd_totlen. As data is successfully moved, this value is decreased.  * At the end of a command, any nonzero residual indicates the number of bytes  * requested by the command but not moved.  *  * The tag cd_xfrlen is the length of the currently active data transfer.  * This allows several interations between any outside software and the  * MD layer to move data.  *  * The reason that total length and total residual have to be tracked  * is to keep track of relative offset.  *  * The tags cd_sense and cd_scsi_status are pretty obvious.  *  * The tag cd_error is to communicate between the MD layer and outer software  * the current error conditions.  *  * The tag cd_lreserved, cd_hreserved are scratch areas for use for the MD  * and outer layers respectively.  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TMD_CDBLEN
end_ifndef

begin_define
define|#
directive|define
name|TMD_CDBLEN
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TMD_SENSELEN
end_ifndef

begin_define
define|#
directive|define
name|TMD_SENSELEN
value|18
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|QCDS
end_ifndef

begin_define
define|#
directive|define
name|QCDS
value|(sizeof (void *))
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
comment|/* private data pointer */
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
name|uint64_t
name|cd_iid
decl_stmt|;
comment|/* initiator ID */
name|uint64_t
name|cd_tgt
decl_stmt|;
comment|/* target id */
name|uint8_t
name|cd_lun
index|[
literal|8
index|]
decl_stmt|;
comment|/* logical unit */
name|uint64_t
name|cd_tagval
decl_stmt|;
comment|/* tag value */
name|uint32_t
name|cd_channel
decl_stmt|;
comment|/* channel index */
name|uint32_t
name|cd_lflags
decl_stmt|;
comment|/* flags lower level sets */
name|uint32_t
name|cd_hflags
decl_stmt|;
comment|/* flags higher level sets */
name|uint32_t
name|cd_totlen
decl_stmt|;
comment|/* total data load */
name|uint32_t
name|cd_resid
decl_stmt|;
comment|/* total data residual */
name|uint32_t
name|cd_xfrlen
decl_stmt|;
comment|/* current data load */
name|int32_t
name|cd_error
decl_stmt|;
comment|/* current error */
name|uint8_t
name|cd_tagtype
decl_stmt|;
comment|/* tag type */
name|uint8_t
name|cd_scsi_status
decl_stmt|;
name|uint8_t
name|cd_sense
index|[
name|TMD_SENSELEN
index|]
decl_stmt|;
name|uint8_t
name|cd_cdb
index|[
name|TMD_CDBLEN
index|]
decl_stmt|;
union|union
block|{
name|void
modifier|*
name|ptrs
index|[
name|QCDS
operator|/
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
name|uint64_t
name|llongs
index|[
name|QCDS
operator|/
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
index|]
decl_stmt|;
name|uint32_t
name|longs
index|[
name|QCDS
operator|/
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
index|]
decl_stmt|;
name|uint16_t
name|shorts
index|[
name|QCDS
operator|/
sizeof|sizeof
argument_list|(
name|uint16_t
argument_list|)
index|]
decl_stmt|;
name|uint8_t
name|bytes
index|[
name|QCDS
index|]
decl_stmt|;
block|}
name|cd_lreserved
index|[
literal|4
index|]
union|,
name|cd_hreserved
index|[
literal|4
index|]
union|;
block|}
name|tmd_cmd_t
typedef|;
end_typedef

begin_comment
comment|/* defined tags */
end_comment

begin_define
define|#
directive|define
name|CD_UNTAGGED
value|0
end_define

begin_define
define|#
directive|define
name|CD_SIMPLE_TAG
value|1
end_define

begin_define
define|#
directive|define
name|CD_ORDERED_TAG
value|2
end_define

begin_define
define|#
directive|define
name|CD_HEAD_TAG
value|3
end_define

begin_define
define|#
directive|define
name|CD_ACA_TAG
value|4
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TMD_SIZE
end_ifndef

begin_define
define|#
directive|define
name|TMD_SIZE
value|(sizeof (tmd_cmd_t))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|L0LUN_TO_FLATLUN
parameter_list|(
name|lptr
parameter_list|)
value|((((lptr)[0]& 0x3f)<< 8) | ((lptr)[1]))
end_define

begin_define
define|#
directive|define
name|FLATLUN_TO_L0LUN
parameter_list|(
name|lptr
parameter_list|,
name|lun
parameter_list|)
define|\
value|(lptr)[1] = lun;                                \     if (sizeof (lun) == 1) {                        \         (lptr)[0] = 0;                              \     } else {                                        \         int nl = (lun);                             \         if (nl< 256) {                             \             (lptr)[0] = 0;                          \         } else {                                    \             (lptr)[0] = 0x40 | ((nl>> 8)& 0x3f);  \         }                                           \     }                                               \     memset(&(lptr)[2], 0, 6)
end_define

begin_comment
comment|/*  * Note that NODISC (obviously) doesn't apply to non-SPI transport.  *  * Note that knowing the data direction and lengh at the time of receipt of  * a command from the initiator is a feature only of Fibre Channel.  *  * The CDFL_BIDIR is in anticipation of the adoption of some newer  * features required by OSD.  *  * The principle selector for MD layer to know whether data is to  * be transferred in any QOUT_TMD_CONT call is cd_xfrlen- the  * flags CDFH_DATA_IN and CDFH_DATA_OUT define which direction.  */
end_comment

begin_define
define|#
directive|define
name|CDFL_SNSVALID
value|0x01
end_define

begin_comment
comment|/* sense data (from f/w) good */
end_comment

begin_define
define|#
directive|define
name|CDFL_SENTSTATUS
value|0x02
end_define

begin_comment
comment|/* last action sent status */
end_comment

begin_define
define|#
directive|define
name|CDFL_DATA_IN
value|0x04
end_define

begin_comment
comment|/* target (us) -> initiator (them) */
end_comment

begin_define
define|#
directive|define
name|CDFL_DATA_OUT
value|0x08
end_define

begin_comment
comment|/* initiator (them) -> target (us) */
end_comment

begin_define
define|#
directive|define
name|CDFL_BIDIR
value|0x0C
end_define

begin_comment
comment|/* bidirectional data */
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
name|CDFL_NODISC
value|0x20
end_define

begin_comment
comment|/* disconnects disabled */
end_comment

begin_define
define|#
directive|define
name|CDFL_SENTSENSE
value|0x40
end_define

begin_comment
comment|/* last action sent sense data */
end_comment

begin_define
define|#
directive|define
name|CDFL_BUSY
value|0x80
end_define

begin_comment
comment|/* this command is not on a free list */
end_comment

begin_define
define|#
directive|define
name|CDFL_PRIVATE
value|0xFF000000
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
comment|/* sense data (from outer layer) good */
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
name|CDFH_PRIVATE
value|0xFF000000
end_define

begin_comment
comment|/* private layer flags */
end_comment

begin_comment
comment|/*  * A word about the START/CONT/DONE/FIN dance:  *  *    When the HBA is enabled for receiving commands, one may show up  *    without notice. When that happens, the MD target mode driver  *    gets a tmd_cmd_t, fills it with the info that just arrived, and  *    calls the outer layer with a QOUT_TMD_START code and pointer to  *    the tmd_cmd_t.  *  *    The outer layer decodes the command, fetches data, prepares stuff,  *    whatever, and starts by passing back the pointer with a QIN_TMD_CONT  *    code which causes the MD target mode driver to generate CTIOs to  *    satisfy whatever action needs to be taken. When those CTIOs complete,  *    the MD target driver sends the pointer to the cmd_tmd_t back with  *    a QOUT_TMD_DONE code. This repeats for as long as necessary. These  *    may not be done in parallel- they are sequential operations.  *  *    The outer layer signals it wants to end the command by settings within  *    the tmd_cmd_t itself. When the final QIN_TMD_CONT is reported completed,  *    the outer layer frees the tmd_cmd_t by sending the pointer to it  *    back with a QIN_TMD_FIN code.  *  *    The graph looks like:  *  *    QOUT_TMD_START -> [ QIN_TMD_CONT -> QOUT_TMD_DONE ] * -> QIN_TMD_FIN.  *  */
end_comment

begin_comment
comment|/*  * Target handler functions.  *  * The MD target handler function (the outer layer calls this)  * should be be prototyped like:  *  *    void target_action(qact_e, void *arg)  *  * The outer layer target handler function (the MD layer calls this)  * should be be prototyped like:  *  *    void scsi_target_handler(tact_e, void *arg)  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ISP_TPUBLIC_H */
end_comment

begin_comment
comment|/*  * vim:ts=4:sw=4:expandtab  */
end_comment

end_unit

