begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vxreg.h	1.1	85/07/21	*/
end_comment

begin_define
define|#
directive|define
name|V_RESETTING
value|1
end_define

begin_comment
comment|/* in process of reseting */
end_comment

begin_define
define|#
directive|define
name|V_RESET
value|1
end_define

begin_comment
comment|/* cause a vioc reset */
end_comment

begin_define
define|#
directive|define
name|V_TRP
value|2
end_define

begin_comment
comment|/* cause a vioc trap */
end_comment

begin_define
define|#
directive|define
name|V_INTR
value|4
end_define

begin_comment
comment|/* cause a vioc interrupt */
end_comment

begin_define
define|#
directive|define
name|V_ERR
value|0x80
end_define

begin_comment
comment|/* generic error flag */
end_comment

begin_define
define|#
directive|define
name|V_BSY
value|0x80
end_define

begin_comment
comment|/* generic busy flag */
end_comment

begin_define
define|#
directive|define
name|V_UNBSY
value|0x80
end_define

begin_comment
comment|/* not busy for unsolicited interrupt */
end_comment

begin_define
define|#
directive|define
name|VCVECT
value|0x40
end_define

begin_comment
comment|/* base vioc vector */
end_comment

begin_define
define|#
directive|define
name|VBAS
parameter_list|(
name|x
parameter_list|)
value|( (struct vblok *)(VIOCBAS[x]) )
end_define

begin_define
define|#
directive|define
name|NVIOCX
value|NVX
end_define

begin_comment
comment|/* nbr of viocx's - defined by config in vx.h */
end_comment

begin_define
define|#
directive|define
name|NVXPORTS
value|16*NVIOCX
end_define

begin_comment
comment|/* Total nbr of viocx terminal ports */
end_comment

begin_define
define|#
directive|define
name|NVCXBUFS
value|16*3
end_define

begin_comment
comment|/* 3 bufs per port per viocx */
end_comment

begin_define
define|#
directive|define
name|VREADY
value|0x55
end_define

begin_comment
comment|/* denotes no err in vioc self-initializaton */
end_comment

begin_define
define|#
directive|define
name|PVIOCX
value|0x0A
end_define

begin_comment
comment|/* old connector panel vioc-x */
end_comment

begin_define
define|#
directive|define
name|VIOCX
value|0x0B
end_define

begin_comment
comment|/* new (modular) connector panel vioc-x */
end_comment

begin_define
define|#
directive|define
name|NPVIOCX
value|0x1A
end_define

begin_comment
comment|/* new pviocx */
end_comment

begin_define
define|#
directive|define
name|NWVIOCX
value|0x1B
end_define

begin_comment
comment|/* new viocx */
end_comment

begin_define
define|#
directive|define
name|VBOPID
value|0x5
end_define

begin_comment
comment|/* Vioc-bop */
end_comment

begin_include
include|#
directive|include
file|"vbsc.h"
end_include

begin_if
if|#
directive|if
name|NVBSC
operator|>
literal|0
end_if

begin_define
define|#
directive|define
name|VIOCB
value|0x0C
end_define

begin_define
define|#
directive|define
name|NWVIOCB
value|0x1C
end_define

begin_define
define|#
directive|define
name|BISYNC
value|0x1
end_define

begin_define
define|#
directive|define
name|LPARAX1
value|0x060a
end_define

begin_define
define|#
directive|define
name|MDMCTL1
value|0x1004
end_define

begin_define
define|#
directive|define
name|HUNTMD1
value|0x0804
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|V_NEW
value|1
end_define

begin_comment
comment|/* NPVIOCX | NVIOCX */
end_comment

begin_define
define|#
directive|define
name|V_OLD
value|0
end_define

begin_comment
comment|/* PVIOCX | VIOCX */
end_comment

begin_comment
comment|/* Modem Control flags */
end_comment

begin_define
define|#
directive|define
name|VMOD_ON
value|1
end_define

begin_define
define|#
directive|define
name|VMOD_OFF
value|0
end_define

begin_define
define|#
directive|define
name|VRESPLEN
value|12
end_define

begin_define
define|#
directive|define
name|VCMDLEN
value|64
end_define

begin_define
define|#
directive|define
name|VC_IQLEN
value|64
end_define

begin_comment
comment|/* Interrupt circular queue length */
end_comment

begin_define
define|#
directive|define
name|VC_CMDBUFL
value|NVCXBUFS
end_define

begin_comment
comment|/* circular cmd (to exec) queue len*/
end_comment

begin_define
define|#
directive|define
name|SSPEED
value|13
end_define

begin_comment
comment|/* standard speed 9600 bps */
end_comment

begin_define
define|#
directive|define
name|V_ENAB
value|0002
end_define

begin_comment
comment|/* auto + DTR */
end_comment

begin_define
define|#
directive|define
name|V_DISAB
value|0000
end_define

begin_comment
comment|/* auto + disable DTR */
end_comment

begin_define
define|#
directive|define
name|BRK_CHR
value|040
end_define

begin_define
define|#
directive|define
name|DCD_ON
value|020
end_define

begin_define
define|#
directive|define
name|DCD_OFF
value|010
end_define

begin_define
define|#
directive|define
name|CTS_ON
value|004
end_define

begin_define
define|#
directive|define
name|DSR_ON
value|0200
end_define

begin_comment
comment|/* modem signal states for bisync */
end_comment

begin_define
define|#
directive|define
name|DSR_OFF
value|0100
end_define

begin_define
define|#
directive|define
name|DSR_CHG
value|(DSR_ON | DSR_OFF)
end_define

begin_define
define|#
directive|define
name|SILOBAS
value|0x800
end_define

begin_comment
comment|/* Command Operation Codes */
end_comment

begin_define
define|#
directive|define
name|LIDENT
value|0x0000
end_define

begin_comment
comment|/* load ident, set int vectors */
end_comment

begin_define
define|#
directive|define
name|XMITDTA
value|0x0200
end_define

begin_comment
comment|/* transmit */
end_comment

begin_define
define|#
directive|define
name|XMITIMM
value|0x0400
end_define

begin_comment
comment|/* xmit immediate */
end_comment

begin_define
define|#
directive|define
name|FDTATOX
value|0x0300
end_define

begin_comment
comment|/* flush data */
end_comment

begin_define
define|#
directive|define
name|LPARAX
value|0x0600
end_define

begin_comment
comment|/* load params */
end_comment

begin_define
define|#
directive|define
name|SNDBRKX
value|0x0C00
end_define

begin_comment
comment|/* send break to port */
end_comment

begin_define
define|#
directive|define
name|MDMCTL
value|0x1000
end_define

begin_comment
comment|/* auto modem control */
end_comment

begin_define
define|#
directive|define
name|PERROR
value|0x40
end_define

begin_define
define|#
directive|define
name|FERROR
value|0x80
end_define

begin_define
define|#
directive|define
name|RCVOVRN
value|0xc0
end_define

begin_comment
comment|/*  * Data Structures  */
end_comment

begin_struct
struct|struct
name|vblok
block|{
comment|/* command sent to vioc  */
name|char
name|v_vioc
decl_stmt|;
comment|/*  0 type of interrupt + voic bsy flg */
name|char
name|v_hdwre
decl_stmt|;
comment|/*  1 trap, reset, or hard interrupt */
name|char
name|v_vcbsy
decl_stmt|;
comment|/*  2 command busy (set by host) */
name|char
name|v_vcid
decl_stmt|;
comment|/*  3 command id. */
name|short
name|v_vcp
index|[
literal|2
index|]
decl_stmt|;
comment|/*  4 command pointer (sent by host) */
name|short
name|v_unused
decl_stmt|;
comment|/*  8 unused */
name|short
name|v_rspoff
decl_stmt|;
comment|/*  a offset into vblock for response buf */
name|char
name|v_ustat
decl_stmt|;
comment|/*  c status */
name|char
name|v_uqual
decl_stmt|;
comment|/*  d qualifies the interrupt */
name|char
name|v_usdata
index|[
literal|0x3E
index|]
decl_stmt|;
comment|/*  e unsolicited interrupt data */
name|short
name|v_maxxmt
decl_stmt|;
comment|/* 4C max xmit block size */
name|short
name|v_maxsilo
decl_stmt|;
comment|/* 4E max silo size */
name|char
name|v_ident
decl_stmt|;
comment|/* 50 identifies type of vioc */
name|char
name|v_fault
decl_stmt|;
comment|/* 51 denotes fault or ready after reset */
name|short
name|v_dcd
decl_stmt|;
comment|/* 52 bit mask for carr detect by port */
name|short
name|v_cts
decl_stmt|;
comment|/* 54 bit mask for cts by port */
name|short
name|v_dsr
decl_stmt|;
comment|/* 56 bit mask for dsr by port */
name|short
name|v_secrec
decl_stmt|;
comment|/* 58 bit mask for secondary receive */
name|short
name|v_badport
decl_stmt|;
comment|/* 5a bit mask of failed ports */
name|char
name|v_portyp
index|[
literal|16
index|]
decl_stmt|;
comment|/* 5c type of each port */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vcmds
block|{
name|int
name|v_cmdsem
decl_stmt|;
comment|/* cmds waiting for itrque */
name|int
name|v_curcnt
decl_stmt|;
comment|/* count of cmds in itrque and executing */
name|caddr_t
name|v_curcmd
index|[
name|VCMDLEN
index|]
decl_stmt|;
comment|/* pointers to cmds being executed */
name|int
name|v_fill
decl_stmt|;
comment|/* circular fill index */
name|int
name|v_empty
decl_stmt|;
comment|/* circular empty index */
name|caddr_t
name|cmdbuf
index|[
name|VC_CMDBUFL
index|]
decl_stmt|;
comment|/* circular cmd (to exec) queue */
name|int
name|v_itrfill
decl_stmt|;
comment|/* circular intr issue queue fill */
name|int
name|v_itrempt
decl_stmt|;
comment|/* circular intr issue queue empty */
name|short
name|v_itrqueu
index|[
name|VC_IQLEN
index|]
decl_stmt|;
comment|/* circular intr issue queue */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vxcmd
block|{
name|struct
name|vxcmd
modifier|*
name|c_fwd
decl_stmt|;
name|short
name|cmd
decl_stmt|;
name|char
name|par
index|[
literal|58
index|]
decl_stmt|;
comment|/* 64 total size */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vxmit
block|{
name|char
name|line
decl_stmt|;
name|char
name|bcount
decl_stmt|;
name|char
name|ostream
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* should be sizeof(struct vxmit), but has alignment problems */
end_comment

begin_define
define|#
directive|define
name|sizvxmit
value|6
end_define

begin_struct
struct|struct
name|vcx
block|{
name|char
name|v_loport
decl_stmt|;
comment|/* low port nbr */
name|char
name|v_hiport
decl_stmt|;
comment|/* high port nbr */
name|short
name|v_nbr
decl_stmt|;
comment|/* viocx number */
name|short
name|v_maxcmd
decl_stmt|;
comment|/* max number of concurrent cmds */
name|short
name|v_silosiz
decl_stmt|;
comment|/* silo size */
name|short
name|v_vers
decl_stmt|;
comment|/* vioc/pvioc version */
name|char
name|v_actflg
decl_stmt|;
comment|/* active command */
name|char
name|v_xmtcnt
decl_stmt|;
comment|/* xmit commands pending */
name|char
name|v_actport
index|[
literal|16
index|]
decl_stmt|;
comment|/* act flag per port per port */
name|short
name|v_brkreq
decl_stmt|;
comment|/* send break requests pending */
name|struct
name|vxcmd
modifier|*
name|vx_avail
decl_stmt|;
name|struct
name|vxcmd
modifier|*
name|vx_build
decl_stmt|;
name|struct
name|vxcmd
name|vx_lst
index|[
name|NVCXBUFS
index|]
decl_stmt|;
name|short
name|v_state
decl_stmt|;
name|caddr_t
name|v_mricmd
decl_stmt|;
comment|/* Most recent issued cmd */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|caddr_t
name|VIOCBAS
index|[
name|NVIOCX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base I/O addr */
end_comment

begin_define
define|#
directive|define
name|vpanic
parameter_list|(
name|x
parameter_list|)
value|printf("%s\n", x)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

