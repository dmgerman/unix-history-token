begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * APM (Advanced Power Management) BIOS Device Driver  *  * Copyright (c) 1994-1995 by HOSOKAWA, Tatsumi<hosokawa@mt.cs.keio.ac.jp>  *  * This software may be used, modified, copied, and distributed, in  * both source and binary form provided that the above copyright and  * these terms are retained. Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with its  * use.  *  * Aug, 1994	Implemented on FreeBSD 1.1.5.1R (Toshiba AVS001WD)  *  *	$Id: apm_bios.h,v 1.10 1996/04/23 16:02:53 nate Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_APM_BIOS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_APM_BIOS_H_
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* BIOS id */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|APM_BIOS
value|0x9a
end_define

begin_define
define|#
directive|define
name|SYSTEM_BIOS
value|0x1f
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|APM_BIOS
value|0x53
end_define

begin_define
define|#
directive|define
name|SYSTEM_BIOS
value|0x15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APM flags */
end_comment

begin_define
define|#
directive|define
name|APM_16BIT_SUPPORT
value|0x01
end_define

begin_define
define|#
directive|define
name|APM_32BIT_SUPPORT
value|0x02
end_define

begin_define
define|#
directive|define
name|APM_CPUIDLE_SLOW
value|0x04
end_define

begin_define
define|#
directive|define
name|APM_DISABLED
value|0x08
end_define

begin_define
define|#
directive|define
name|APM_DISENGAGED
value|0x10
end_define

begin_comment
comment|/* APM initializer physical address */
end_comment

begin_define
define|#
directive|define
name|APM_OURADDR
value|0x00080000
end_define

begin_comment
comment|/* Error code of APM initializer */
end_comment

begin_define
define|#
directive|define
name|APMINI_CANTFIND
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|APMINI_NOT32BIT
value|0xfffffffe
end_define

begin_define
define|#
directive|define
name|APMINI_CONNECTERR
value|0xfffffffd
end_define

begin_comment
comment|/* APM functions */
end_comment

begin_define
define|#
directive|define
name|APM_INSTCHECK
value|0x00
end_define

begin_define
define|#
directive|define
name|APM_REALCONNECT
value|0x01
end_define

begin_define
define|#
directive|define
name|APM_PROT16CONNECT
value|0x02
end_define

begin_define
define|#
directive|define
name|APM_PROT32CONNECT
value|0x03
end_define

begin_define
define|#
directive|define
name|APM_DISCONNECT
value|0x04
end_define

begin_define
define|#
directive|define
name|APM_CPUIDLE
value|0x05
end_define

begin_define
define|#
directive|define
name|APM_CPUBUSY
value|0x06
end_define

begin_define
define|#
directive|define
name|APM_SETPWSTATE
value|0x07
end_define

begin_define
define|#
directive|define
name|APM_ENABLEDISABLEPM
value|0x08
end_define

begin_define
define|#
directive|define
name|APM_RESTOREDEFAULT
value|0x09
end_define

begin_define
define|#
directive|define
name|APM_GETPWSTATUS
value|0x0a
end_define

begin_define
define|#
directive|define
name|APM_GETPMEVENT
value|0x0b
end_define

begin_define
define|#
directive|define
name|APM_GETPWSTATE
value|0x0c
end_define

begin_define
define|#
directive|define
name|APM_ENABLEDISABLEDPM
value|0x0d
end_define

begin_define
define|#
directive|define
name|APM_DRVVERSION
value|0x0e
end_define

begin_define
define|#
directive|define
name|APM_ENGAGEDISENGAGEPM
value|0x0f
end_define

begin_define
define|#
directive|define
name|APM_OEMFUNC
value|0x80
end_define

begin_comment
comment|/* error code */
end_comment

begin_define
define|#
directive|define
name|APME_OK
value|0x00
end_define

begin_define
define|#
directive|define
name|APME_PMDISABLED
value|0x01
end_define

begin_define
define|#
directive|define
name|APME_REALESTABLISHED
value|0x02
end_define

begin_define
define|#
directive|define
name|APME_NOTCONNECTED
value|0x03
end_define

begin_define
define|#
directive|define
name|APME_PROT16ESTABLISHED
value|0x05
end_define

begin_define
define|#
directive|define
name|APME_PROT16NOTSUPPORTED
value|0x06
end_define

begin_define
define|#
directive|define
name|APME_PROT32ESTABLISHED
value|0x07
end_define

begin_define
define|#
directive|define
name|APME_PROT32NOTDUPPORTED
value|0x08
end_define

begin_define
define|#
directive|define
name|APME_UNKNOWNDEVICEID
value|0x09
end_define

begin_define
define|#
directive|define
name|APME_OUTOFRANGE
value|0x0a
end_define

begin_define
define|#
directive|define
name|APME_NOTENGAGED
value|0x0b
end_define

begin_define
define|#
directive|define
name|APME_CANTENTERSTATE
value|0x60
end_define

begin_define
define|#
directive|define
name|APME_NOPMEVENT
value|0x80
end_define

begin_define
define|#
directive|define
name|APME_NOAPMPRESENT
value|0x86
end_define

begin_comment
comment|/* device code */
end_comment

begin_define
define|#
directive|define
name|PMDV_APMBIOS
value|0x0000
end_define

begin_define
define|#
directive|define
name|PMDV_ALLDEV
value|0x0001
end_define

begin_define
define|#
directive|define
name|PMDV_DISP0
value|0x0100
end_define

begin_define
define|#
directive|define
name|PMDV_DISP1
value|0x0101
end_define

begin_define
define|#
directive|define
name|PMDV_2NDSTORAGE0
value|0x0200
end_define

begin_define
define|#
directive|define
name|PMDV_2NDSTORAGE1
value|0x0201
end_define

begin_define
define|#
directive|define
name|PMDV_2NDSTORAGE2
value|0x0202
end_define

begin_define
define|#
directive|define
name|PMDV_2NDSTORAGE3
value|0x0203
end_define

begin_define
define|#
directive|define
name|PMDV_PARALLEL0
value|0x0300
end_define

begin_define
define|#
directive|define
name|PMDV_PARALLEL1
value|0x0301
end_define

begin_define
define|#
directive|define
name|PMDV_SERIAL0
value|0x0400
end_define

begin_define
define|#
directive|define
name|PMDV_SERIAL1
value|0x0401
end_define

begin_define
define|#
directive|define
name|PMDV_SERIAL2
value|0x0402
end_define

begin_define
define|#
directive|define
name|PMDV_SERIAL3
value|0x0403
end_define

begin_define
define|#
directive|define
name|PMDV_SERIAL4
value|0x0404
end_define

begin_define
define|#
directive|define
name|PMDV_SERIAL5
value|0x0405
end_define

begin_define
define|#
directive|define
name|PMDV_SERIAL6
value|0x0406
end_define

begin_define
define|#
directive|define
name|PMDV_SERIAL7
value|0x0407
end_define

begin_define
define|#
directive|define
name|PMDV_NET0
value|0x0500
end_define

begin_define
define|#
directive|define
name|PMDV_NET1
value|0x0501
end_define

begin_define
define|#
directive|define
name|PMDV_NET2
value|0x0502
end_define

begin_define
define|#
directive|define
name|PMDV_NET3
value|0x0503
end_define

begin_define
define|#
directive|define
name|PMDV_PCMCIA0
value|0x0600
end_define

begin_define
define|#
directive|define
name|PMDV_PCMCIA1
value|0x0601
end_define

begin_define
define|#
directive|define
name|PMDV_PCMCIA2
value|0x0602
end_define

begin_define
define|#
directive|define
name|PMDV_PCMCIA3
value|0x0603
end_define

begin_comment
comment|/* 0x0700 - 0xdfff	Reserved			*/
end_comment

begin_comment
comment|/* 0xe000 - 0xefff	OEM-defined power device IDs	*/
end_comment

begin_comment
comment|/* 0xf000 - 0xffff	Reserved			*/
end_comment

begin_comment
comment|/* Power state */
end_comment

begin_define
define|#
directive|define
name|PMST_APMENABLED
value|0x0000
end_define

begin_define
define|#
directive|define
name|PMST_STANDBY
value|0x0001
end_define

begin_define
define|#
directive|define
name|PMST_SUSPEND
value|0x0002
end_define

begin_define
define|#
directive|define
name|PMST_OFF
value|0x0003
end_define

begin_define
define|#
directive|define
name|PMST_LASTREQNOTIFY
value|0x0004
end_define

begin_define
define|#
directive|define
name|PMST_LASTREQREJECT
value|0x0005
end_define

begin_comment
comment|/* 0x0006 - 0x001f	Reserved system states		*/
end_comment

begin_comment
comment|/* 0x0020 - 0x003f	OEM-defined system states	*/
end_comment

begin_comment
comment|/* 0x0040 - 0x007f	OEM-defined device states	*/
end_comment

begin_comment
comment|/* 0x0080 - 0xffff	Reserved device states		*/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ASSEMBLER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|INITIALIZER
argument_list|)
end_if

begin_comment
comment|/* C definitions */
end_comment

begin_struct
struct|struct
name|apmhook
block|{
name|struct
name|apmhook
modifier|*
name|ah_next
decl_stmt|;
name|int
argument_list|(
argument|*ah_fun
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|ah_arg
operator|)
argument_list|)
expr_stmt|;
name|void
modifier|*
name|ah_arg
decl_stmt|;
specifier|const
name|char
modifier|*
name|ah_name
decl_stmt|;
name|int
name|ah_order
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|APM_HOOK_NONE
value|(-1)
end_define

begin_define
define|#
directive|define
name|APM_HOOK_SUSPEND
value|0
end_define

begin_define
define|#
directive|define
name|APM_HOOK_RESUME
value|1
end_define

begin_define
define|#
directive|define
name|NAPM_HOOK
value|2
end_define

begin_function_decl
name|void
name|apm_suspend
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|apmhook
modifier|*
name|apm_hook_establish
parameter_list|(
name|int
name|apmh
parameter_list|,
name|struct
name|apmhook
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|apm_hook_disestablish
parameter_list|(
name|int
name|apmh
parameter_list|,
name|struct
name|apmhook
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|apm_cpu_idle
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|apm_cpu_busy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ASSEMBLER&& !INITIALIZER */
end_comment

begin_define
define|#
directive|define
name|APM_MIN_ORDER
value|0x00
end_define

begin_define
define|#
directive|define
name|APM_MID_ORDER
value|0x80
end_define

begin_define
define|#
directive|define
name|APM_MAX_ORDER
value|0xff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/* power management event code */
end_comment

begin_define
define|#
directive|define
name|PMEV_NOEVENT
value|0x0000
end_define

begin_define
define|#
directive|define
name|PMEV_STANDBYREQ
value|0x0001
end_define

begin_define
define|#
directive|define
name|PMEV_SUSPENDREQ
value|0x0002
end_define

begin_define
define|#
directive|define
name|PMEV_NORMRESUME
value|0x0003
end_define

begin_define
define|#
directive|define
name|PMEV_CRITRESUME
value|0x0004
end_define

begin_define
define|#
directive|define
name|PMEV_BATTERYLOW
value|0x0005
end_define

begin_define
define|#
directive|define
name|PMEV_POWERSTATECHANGE
value|0x0006
end_define

begin_define
define|#
directive|define
name|PMEV_UPDATETIME
value|0x0007
end_define

begin_define
define|#
directive|define
name|PMEV_CRITSUSPEND
value|0x0008
end_define

begin_define
define|#
directive|define
name|PMEV_USERSTANDBYREQ
value|0x0009
end_define

begin_define
define|#
directive|define
name|PMEV_USERSUSPENDREQ
value|0x000a
end_define

begin_define
define|#
directive|define
name|PMEV_STANDBYRESUME
value|0x000b
end_define

begin_comment
comment|/* 0x000c - 0x00ff	Reserved system events	*/
end_comment

begin_comment
comment|/* 0x0100 - 0x01ff	Reserved device events	*/
end_comment

begin_comment
comment|/* 0x0200 - 0x02ff	OEM-defined APM events	*/
end_comment

begin_comment
comment|/* 0x0300 - 0xffff	Reserved		*/
end_comment

begin_define
define|#
directive|define
name|PMEV_DEFAULT
value|0xffffffff
end_define

begin_comment
comment|/* used for customization */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ASSEMBLER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|INITIALIZER
argument_list|)
end_if

begin_typedef
typedef|typedef
struct|struct
name|apm_info
block|{
name|u_int
name|ai_major
decl_stmt|;
comment|/* APM major version */
name|u_int
name|ai_minor
decl_stmt|;
comment|/* APM minor version */
name|u_int
name|ai_acline
decl_stmt|;
comment|/* AC line status */
name|u_int
name|ai_batt_stat
decl_stmt|;
comment|/* Battery status */
name|u_int
name|ai_batt_life
decl_stmt|;
comment|/* Remaining battery life */
name|u_int
name|ai_status
decl_stmt|;
comment|/* Status of APM support (enabled/disabled) */
block|}
typedef|*
name|apm_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|APMIO_SUSPEND
value|_IO('P', 1)
end_define

begin_define
define|#
directive|define
name|APMIO_GETINFO
value|_IOR('P', 2, struct apm_info)
end_define

begin_define
define|#
directive|define
name|APMIO_ENABLE
value|_IO('P', 5)
end_define

begin_define
define|#
directive|define
name|APMIO_DISABLE
value|_IO('P', 6)
end_define

begin_define
define|#
directive|define
name|APMIO_HALTCPU
value|_IO('P', 7)
end_define

begin_define
define|#
directive|define
name|APMIO_NOTHALTCPU
value|_IO('P', 8)
end_define

begin_define
define|#
directive|define
name|APMIO_DISPLAYOFF
value|_IO('P', 9)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ASSEMBLER&& !INITIALIZER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_APM_BIOS_H_ */
end_comment

end_unit

