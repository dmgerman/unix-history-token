begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2001 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_ioctl.h - messages kernel<--> userland  *	-------------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Sat Jul 21 12:24:56 2001]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_IOCTL_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD__
operator|>=
literal|3
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TYPES_H_
end_ifndef

begin_include
include|#
directive|include
file|<machine/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_TYPES_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	version and release number for isdn4bsd package  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|VERSION
value|1
end_define

begin_comment
comment|/* version number	*/
end_comment

begin_define
define|#
directive|define
name|REL
value|0
end_define

begin_comment
comment|/* release number	*/
end_comment

begin_define
define|#
directive|define
name|STEP
value|1
end_define

begin_comment
comment|/* release step		*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  * date/time format in i4b log messages  * ------------------------------------  * Being year 2000 clean is not easy with the current state of the  * ANSI C library standard and it's implementation for some locales.  * You might like to use the "%c" format of "strftime" sometimes,  * but this breaks Y2K in some locales. Also the old standard logfile  * format "%d.%m.%y %H:%M:%S" is non compliant.  * NetBSD's current toolset warns about this problems, and we compile  * with -Werror, so this problems need to be resolved.  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|I4B_TIME_FORMAT
value|"%d.%m.%Y %H:%M:%S"
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	max number of controllers in system  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|MAX_CONTROLLERS
value|8
end_define

begin_comment
comment|/* max number of controllers	*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	ISDN D-channel protocols   *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|PROTOCOL_DSS1
value|0
end_define

begin_comment
comment|/* default, Euro-ISDN/DSS1 */
end_comment

begin_define
define|#
directive|define
name|PROTOCOL_D64S
value|1
end_define

begin_comment
comment|/* 64k leased line, no protocol */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	controller types  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|CTRL_INVALID
value|(-1)
end_define

begin_comment
comment|/* invalid, error		*/
end_comment

begin_define
define|#
directive|define
name|CTRL_UNKNOWN
value|0
end_define

begin_comment
comment|/* unknown controller type	*/
end_comment

begin_define
define|#
directive|define
name|CTRL_PASSIVE
value|1
end_define

begin_comment
comment|/* passive ISDN controller cards*/
end_comment

begin_define
define|#
directive|define
name|CTRL_DAIC
value|2
end_define

begin_comment
comment|/* Diehl active controller cards*/
end_comment

begin_define
define|#
directive|define
name|CTRL_TINADD
value|3
end_define

begin_comment
comment|/* Stollmann Tina-dd active card*/
end_comment

begin_define
define|#
directive|define
name|CTRL_AVMB1
value|4
end_define

begin_comment
comment|/* AVM B1 active card		*/
end_comment

begin_define
define|#
directive|define
name|CTRL_CAPI
value|5
end_define

begin_comment
comment|/* cards seen via the CAPI layer*/
end_comment

begin_define
define|#
directive|define
name|CTRL_NUMTYPES
value|6
end_define

begin_comment
comment|/* number of controller types	*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	CTRL_PASSIVE: driver types  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|MAXL1UNITS
value|8
end_define

begin_comment
comment|/* max number of units	*/
end_comment

begin_define
define|#
directive|define
name|L1DRVR_ISIC
value|0
end_define

begin_comment
comment|/* isic - driver	*/
end_comment

begin_define
define|#
directive|define
name|L1DRVR_IWIC
value|1
end_define

begin_comment
comment|/* iwic - driver	*/
end_comment

begin_define
define|#
directive|define
name|L1DRVR_IFPI
value|2
end_define

begin_comment
comment|/* ifpi - driver	*/
end_comment

begin_define
define|#
directive|define
name|L1DRVR_IHFC
value|3
end_define

begin_comment
comment|/* ihfc - driver	*/
end_comment

begin_define
define|#
directive|define
name|L1DRVR_IFPNP
value|4
end_define

begin_comment
comment|/* ifpnp - driver	*/
end_comment

begin_define
define|#
directive|define
name|L1DRVR_ICCHP
value|5
end_define

begin_comment
comment|/* icchp - driver	*/
end_comment

begin_define
define|#
directive|define
name|L1DRVR_ITJC
value|6
end_define

begin_comment
comment|/* itjc - driver	*/
end_comment

begin_comment
comment|/* MAXL1DRVR MUST be updated when more passive drivers are added !!! */
end_comment

begin_define
define|#
directive|define
name|MAXL1DRVR
value|(L1DRVR_ITJC + 1)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	card types for CTRL_PASSIVE   *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_INVAL
value|(-1)
end_define

begin_comment
comment|/* invalid, error		*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_UNK
value|0
end_define

begin_comment
comment|/* unknown			*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_8
value|1
end_define

begin_comment
comment|/* Teles, S0/8 			*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_16
value|2
end_define

begin_comment
comment|/* Teles, S0/16			*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_16_3
value|3
end_define

begin_comment
comment|/* Teles, S0/16.3		*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_AVMA1
value|4
end_define

begin_comment
comment|/* AVM A1 or AVM Fritz!Card	*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_163P
value|5
end_define

begin_comment
comment|/* Teles, S0/16.3 PnP		*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_CS0P
value|6
end_define

begin_comment
comment|/* Creatix, S0 PnP		*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_USRTA
value|7
end_define

begin_comment
comment|/* US Robotics ISDN TA internal	*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_DRNNGO
value|8
end_define

begin_comment
comment|/* Dr. Neuhaus Niccy GO@	*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_SWS
value|9
end_define

begin_comment
comment|/* Sedlbauer Win Speed		*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_DYNALINK
value|10
end_define

begin_comment
comment|/* Dynalink IS64PH		*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_BLMASTER
value|11
end_define

begin_comment
comment|/* ISDN Blaster / ISDN Master	*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_PCFRITZ
value|12
end_define

begin_comment
comment|/* AVM PCMCIA Fritz!Card	*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_ELSAQS1ISA
value|13
end_define

begin_comment
comment|/* ELSA QuickStep 1000pro ISA	*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_ELSAQS1PCI
value|14
end_define

begin_comment
comment|/* ELSA QuickStep 1000pro PCI	*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_SIEMENSITALK
value|15
end_define

begin_comment
comment|/* Siemens I-Talk		*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_ELSAMLIMC
value|16
end_define

begin_comment
comment|/* ELSA MicroLink ISDN/MC	*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_ELSAMLMCALL
value|17
end_define

begin_comment
comment|/* ELSA MicroLink MCall		*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_ITKIX1
value|18
end_define

begin_comment
comment|/* ITK ix1 micro 		*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_AVMA1PCI
value|19
end_define

begin_comment
comment|/* AVM FRITZ!CARD PCI		*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_PCC16
value|20
end_define

begin_comment
comment|/* ELSA PCC-16			*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_AVM_PNP
value|21
end_define

begin_comment
comment|/* AVM FRITZ!CARD PnP		*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_SIE_ISURF2
value|22
end_define

begin_comment
comment|/* Siemens I-Surf 2 PnP		*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_ASUSCOMIPAC
value|23
end_define

begin_comment
comment|/* Asuscom ISDNlink 128 K PnP	*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_WINB6692
value|24
end_define

begin_comment
comment|/* Winbond W6692 based		*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_16_3C
value|25
end_define

begin_comment
comment|/* Teles S0/16.3c PnP (HFC-S/SP	*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_ACERP10
value|26
end_define

begin_comment
comment|/* Acer ISDN P10 (HFC-S)	*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_TELEINT_NO_1
value|27
end_define

begin_comment
comment|/* TELEINT ISDN SPEED No. 1 (HFC-1) */
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_CCD_HFCS_PCI
value|28
end_define

begin_comment
comment|/* Cologne Chip HFC-S PCI based	*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_NETJET_S
value|29
end_define

begin_comment
comment|/* Traverse NetJet-S (Tiger300) */
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_DIVA_ISA
value|30
end_define

begin_comment
comment|/* Eicon DIVA ISA PnP 2.0 or 2.02 */
end_comment

begin_comment
comment|/*  * in case you add support for more cards, please update:  *  *	isdnd:		controller.c, name_of_controller()  *  * and adjust CARD_TYPEP_MAX below.  */
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEP_MAX
value|30
end_define

begin_comment
comment|/* max type */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	card types for CTRL_DAIC  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEA_DAIC_UNK
value|0
end_define

begin_define
define|#
directive|define
name|CARD_TYPEA_DAIC_S
value|1
end_define

begin_define
define|#
directive|define
name|CARD_TYPEA_DAIC_SX
value|2
end_define

begin_define
define|#
directive|define
name|CARD_TYPEA_DAIC_SCOM
value|3
end_define

begin_define
define|#
directive|define
name|CARD_TYPEA_DAIC_QUAD
value|4
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	card types for CTRL_CAPI  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|CARD_TYPEC_CAPI_UNK
value|0
end_define

begin_define
define|#
directive|define
name|CARD_TYPEC_AVM_T1_PCI
value|1
end_define

begin_define
define|#
directive|define
name|CARD_TYPEC_AVM_B1_PCI
value|2
end_define

begin_define
define|#
directive|define
name|CARD_TYPEC_AVM_B1_ISA
value|3
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	max length of some strings  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|TELNO_MAX
value|41
end_define

begin_comment
comment|/* max length of a telephone number (+ '\0')  */
end_comment

begin_define
define|#
directive|define
name|DISPLAY_MAX
value|91
end_define

begin_comment
comment|/* max length of display information (+ '\0') */
end_comment

begin_define
define|#
directive|define
name|DATETIME_MAX
value|21
end_define

begin_comment
comment|/* max length of datetime information (+ '\0')*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	in case the src or dst telephone number is empty  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|TELNO_EMPTY
value|"NotAvailable"
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	B channel parameters  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|BCH_MAX_DATALEN
value|2048
end_define

begin_comment
comment|/* max length of a B channel frame */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  * userland driver types  * ---------------------  * a "driver" is defined here as a piece of software interfacing an   * ISDN B channel with a userland service, such as IP, Telephony etc.  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|BDRV_RBCH
value|0
end_define

begin_comment
comment|/* raw b-channel interface driver       */
end_comment

begin_define
define|#
directive|define
name|BDRV_TEL
value|1
end_define

begin_comment
comment|/* telephone (speech) interface driver  */
end_comment

begin_define
define|#
directive|define
name|BDRV_IPR
value|2
end_define

begin_comment
comment|/* IP over raw HDLC interface driver    */
end_comment

begin_define
define|#
directive|define
name|BDRV_ISPPP
value|3
end_define

begin_comment
comment|/* sync Kernel PPP interface driver     */
end_comment

begin_define
define|#
directive|define
name|BDRV_IBC
value|4
end_define

begin_comment
comment|/* BSD/OS point to point driver		*/
end_comment

begin_define
define|#
directive|define
name|BDRV_ING
value|5
end_define

begin_comment
comment|/* NetGraph ing driver			*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  * B channel protocol  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|BPROT_NONE
value|0
end_define

begin_comment
comment|/* no protocol at all, raw data		*/
end_comment

begin_define
define|#
directive|define
name|BPROT_RHDLC
value|1
end_define

begin_comment
comment|/* raw HDLC: flag, data, crc, flag	*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  * causes data type  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|cause_t
typedef|;
end_typedef

begin_comment
comment|/* 32 bit unsigned int	*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  * call descriptor id (cdid) definitions  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|CDID_UNUSED
value|0
end_define

begin_comment
comment|/* cdid is invalid and unused		*/
end_comment

begin_define
define|#
directive|define
name|CDID_MAX
value|99999
end_define

begin_comment
comment|/* highest valid cdid, wraparound to 1	*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	The shorthold algorithm to use  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|SHA_FIXU
value|0
end_define

begin_comment
comment|/* timeout algorithm for fix unit charging */
end_comment

begin_define
define|#
directive|define
name|SHA_VARU
value|1
end_define

begin_comment
comment|/* timeout algorithm for variable unit charging */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	The shorthold data struct  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|shorthold_algorithm
decl_stmt|;
comment|/* shorthold algorithm to use	*/
name|int
name|unitlen_time
decl_stmt|;
comment|/* length of a charging unit	*/
name|int
name|idle_time
decl_stmt|;
comment|/* time without activity on b ch*/
name|int
name|earlyhup_time
decl_stmt|;
comment|/* safety area at end of unit	*/
block|}
name|msg_shorthold_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************  	outgoing call: 	--------------  		userland		kernel 		--------		------  		CDID_REQ -----------------><------------------ cdid 	 		CONNECT_REQ --------------><------------------ PROCEEDING_IND (if connect req ok)<------------------ CONNECT_ACTIVE_IND (if connection ok)  		or<------------------ DISCONNECT_IND (if connection failed) 	             		  	incoming call: 	--------------  		userland		kernel 		--------		------<------------------ CONNECT_IND  		CONNECT_RESP -------------><------------------ CONNECT_ACTIVE_IND (if accepted)    	active disconnect: 	------------------  		userland		kernel 		--------		------  		DISCONNECT_REQ ------------><------------------ DISCONNECT_IND 	              	passive disconnect: 	-------------------  		userland		kernel 		--------		------<------------------ DISCONNECT_IND 	              ****************************************************************************/
end_comment

begin_comment
comment|/*===========================================================================*  *===========================================================================*  *	"read" messages from kernel -> userland  *===========================================================================*   *===========================================================================*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	message header, included in every message  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|type
decl_stmt|;
comment|/* message identifier		*/
define|#
directive|define
name|MSG_CONNECT_IND
value|'a'
define|#
directive|define
name|MSG_CONNECT_ACTIVE_IND
value|'b'
define|#
directive|define
name|MSG_DISCONNECT_IND
value|'c'
define|#
directive|define
name|MSG_DIALOUT_IND
value|'d'
define|#
directive|define
name|MSG_IDLE_TIMEOUT_IND
value|'e'
define|#
directive|define
name|MSG_ACCT_IND
value|'f'
define|#
directive|define
name|MSG_CHARGING_IND
value|'g'
define|#
directive|define
name|MSG_PROCEEDING_IND
value|'h'
define|#
directive|define
name|MSG_ALERT_IND
value|'i'
define|#
directive|define
name|MSG_DRVRDISC_REQ
value|'j'
define|#
directive|define
name|MSG_L12STAT_IND
value|'k'
define|#
directive|define
name|MSG_TEIASG_IND
value|'l'
define|#
directive|define
name|MSG_PDEACT_IND
value|'m'
define|#
directive|define
name|MSG_NEGCOMP_IND
value|'n'
define|#
directive|define
name|MSG_IFSTATE_CHANGED_IND
value|'o'
define|#
directive|define
name|MSG_DIALOUTNUMBER_IND
value|'p'
define|#
directive|define
name|MSG_PACKET_IND
value|'q'
name|int
name|cdid
decl_stmt|;
comment|/* call descriptor id		*/
block|}
name|msg_hdr_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	connect indication  *		indicates incoming connection  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header		*/
name|int
name|controller
decl_stmt|;
comment|/* controller number		*/
name|int
name|channel
decl_stmt|;
comment|/* channel number		*/
define|#
directive|define
name|CHAN_B1
value|0
comment|/* this _must_ be 0, HSCX B1 is also 0	*/
define|#
directive|define
name|CHAN_B2
value|1
comment|/* this _must_ be 1, HSCX B2 is also 1	*/
define|#
directive|define
name|CHAN_ANY
value|(-1)
comment|/* outgoing, not possible for incoming	*/
define|#
directive|define
name|CHAN_NO
value|(-2)
comment|/* call waiting (CW) for incoming	*/
name|int
name|bprot
decl_stmt|;
comment|/* b channel protocot, see BPROT_XXX	*/
name|char
name|dst_telno
index|[
name|TELNO_MAX
index|]
decl_stmt|;
comment|/* destination telno	*/
name|char
name|src_telno
index|[
name|TELNO_MAX
index|]
decl_stmt|;
comment|/* source telno		*/
name|int
name|scr_ind
decl_stmt|;
comment|/* screening indicator			*/
define|#
directive|define
name|SCR_NONE
value|0
comment|/* no screening indicator transmitted	*/
define|#
directive|define
name|SCR_USR_NOSC
value|1
comment|/* screening user provided, not screened*/
define|#
directive|define
name|SCR_USR_PASS
value|2
comment|/* screening user provided, verified& passed */
define|#
directive|define
name|SCR_USR_FAIL
value|3
comment|/* screening user provided, verified& failed */
define|#
directive|define
name|SCR_NET
value|4
comment|/* screening network provided		*/
name|int
name|prs_ind
decl_stmt|;
comment|/* presentation indicator		*/
define|#
directive|define
name|PRS_NONE
value|0
comment|/* no presentation indicator transmitted*/
define|#
directive|define
name|PRS_ALLOWED
value|1
comment|/* presentation allowed			*/
define|#
directive|define
name|PRS_RESTRICT
value|2
comment|/* presentation restricted		*/
define|#
directive|define
name|PRS_NNINTERW
value|3
comment|/* number not available due to interworking */
define|#
directive|define
name|PRS_RESERVED
value|4
comment|/* reserved				*/
name|char
name|display
index|[
name|DISPLAY_MAX
index|]
decl_stmt|;
comment|/* content of display IE*/
block|}
name|msg_connect_ind_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	connect active indication  *		indicates active connection  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header		   */
name|int
name|controller
decl_stmt|;
comment|/* controller number actually used */
name|int
name|channel
decl_stmt|;
comment|/* channel number actually used    */
name|char
name|datetime
index|[
name|DATETIME_MAX
index|]
decl_stmt|;
comment|/* content of date/time IE */
block|}
name|msg_connect_active_ind_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	disconnect indication  *		indicates a disconnect  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header	*/
name|cause_t
name|cause
decl_stmt|;
comment|/* cause code		*/
block|}
name|msg_disconnect_ind_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	negotiation complete  *		indicates an interface is completely up& running  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header	*/
block|}
name|msg_negcomplete_ind_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	interface changes internal state  *		indicates an interface has somehow switched its FSM  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header	*/
name|int
name|state
decl_stmt|;
comment|/* new interface state */
block|}
name|msg_ifstatechg_ind_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	initiate a call to a remote site  *		i.e. the IP driver got a packet and wants a connection  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header	*/
name|int
name|driver
decl_stmt|;
comment|/* driver type		*/
name|int
name|driver_unit
decl_stmt|;
comment|/* driver unit number	*/
block|}
name|msg_dialout_ind_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	dial a number  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header	*/
name|int
name|driver
decl_stmt|;
comment|/* driver type		*/
name|int
name|driver_unit
decl_stmt|;
comment|/* driver unit number	*/
name|int
name|cmdlen
decl_stmt|;
comment|/* length of string	*/
name|char
name|cmd
index|[
name|TELNO_MAX
index|]
decl_stmt|;
comment|/* the number to dial	*/
block|}
name|msg_dialoutnumber_ind_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	idle timeout disconnect sent indication  *		kernel has sent disconnect request because of b-ch idle  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header	*/
block|}
name|msg_idle_timeout_ind_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	accounting information from userland interface driver to daemon  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header		*/
name|int
name|accttype
decl_stmt|;
comment|/* accounting type		*/
define|#
directive|define
name|ACCT_DURING
value|0
define|#
directive|define
name|ACCT_FINAL
value|1
name|int
name|driver
decl_stmt|;
comment|/* driver type			*/
name|int
name|driver_unit
decl_stmt|;
comment|/* driver unit number		*/
name|int
name|ioutbytes
decl_stmt|;
comment|/* ISDN # of bytes sent		*/
name|int
name|iinbytes
decl_stmt|;
comment|/* ISDN # of bytes received	*/
name|int
name|outbps
decl_stmt|;
comment|/* bytes per sec out		*/
name|int
name|inbps
decl_stmt|;
comment|/* bytes per sec in		*/
name|int
name|outbytes
decl_stmt|;
comment|/* driver # of bytes sent	*/
name|int
name|inbytes
decl_stmt|;
comment|/* driver # of bytes received	*/
block|}
name|msg_accounting_ind_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	charging information from isdn driver to daemon  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header		*/
name|int
name|units
decl_stmt|;
comment|/* number of units		*/
name|int
name|units_type
decl_stmt|;
comment|/* type of units info		*/
define|#
directive|define
name|CHARGE_INVALID
value|0
comment|/* invalid, unknown */
define|#
directive|define
name|CHARGE_AOCD
value|1
comment|/* advice of charge during call */
define|#
directive|define
name|CHARGE_AOCE
value|2
comment|/* advice of charge at end of call */
define|#
directive|define
name|CHARGE_CALC
value|3
comment|/* locally calculated from rates information */
block|}
name|msg_charging_ind_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	call proceeding indication  *		indicates outgoing SETUP has been acknowleged  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header		   */
name|int
name|controller
decl_stmt|;
comment|/* controller number actually used */
name|int
name|channel
decl_stmt|;
comment|/* channel number actually used    */
block|}
name|msg_proceeding_ind_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	alert indication  *		indicates remote user side "rings"  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header		   */
block|}
name|msg_alert_ind_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	driver requests to disconnect line  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header	*/
name|int
name|driver
decl_stmt|;
comment|/* driver type		*/
name|int
name|driver_unit
decl_stmt|;
comment|/* driver unit number	*/
block|}
name|msg_drvrdisc_req_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	connect packet logging  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header	*/
name|int
name|driver
decl_stmt|;
comment|/* driver type		*/
name|int
name|driver_unit
decl_stmt|;
comment|/* driver unit number	*/
name|int
name|direction
decl_stmt|;
comment|/* 0=in 1=out		*/
define|#
directive|define
name|DIRECTION_IN
value|0
comment|/* sending packet to remote	*/
define|#
directive|define
name|DIRECTION_OUT
value|1
comment|/* received packet from remote	*/
define|#
directive|define
name|MAX_PACKET_LOG
value|40
comment|/* space for IP and TCP header	*/
name|u_int8_t
name|pktdata
index|[
name|MAX_PACKET_LOG
index|]
decl_stmt|;
block|}
name|msg_packet_ind_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	state of layer 1/2  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header	*/
name|int
name|controller
decl_stmt|;
comment|/* controller unit 	*/
name|int
name|layer
decl_stmt|;
comment|/* layer number (1/2)	*/
define|#
directive|define
name|LAYER_ONE
value|1
define|#
directive|define
name|LAYER_TWO
value|2
name|int
name|state
decl_stmt|;
comment|/* state info		*/
define|#
directive|define
name|LAYER_IDLE
value|0
define|#
directive|define
name|LAYER_ACTIVE
value|1
block|}
name|msg_l12stat_ind_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	TEI assignment messages  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header	*/
name|int
name|controller
decl_stmt|;
comment|/* controller unit 	*/
name|int
name|tei
decl_stmt|;
comment|/* TEI or -1 if invalid */
block|}
name|msg_teiasg_ind_t
typedef|;
end_typedef

begin_comment
comment|/*---------------------------------------------------------------------------*  *	persistent deactivation state of stack  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|msg_hdr_t
name|header
decl_stmt|;
comment|/* common header	*/
name|int
name|controller
decl_stmt|;
comment|/* controller unit 	*/
name|int
name|numactive
decl_stmt|;
comment|/* number of active connections */
block|}
name|msg_pdeact_ind_t
typedef|;
end_typedef

begin_comment
comment|/*===========================================================================*  *===========================================================================*  *	"ioctl" messages from userland -> kernel  *===========================================================================*   *===========================================================================*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	request a unique cdid (to setup an outgoing call)  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|cdid
decl_stmt|;
comment|/* call descriptor id	*/
block|}
name|msg_cdid_req_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I4B_CDID_REQ
value|_IOWR('4', 0, int)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	connect request  *		requests an outgoing connection  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|cdid
decl_stmt|;
comment|/* call descriptor id		     */
name|int
name|controller
decl_stmt|;
comment|/* controller to use		     */
name|int
name|channel
decl_stmt|;
comment|/* channel to use		     */
name|int
name|txdelay
decl_stmt|;
comment|/* tx delay after connect	     */
name|int
name|bprot
decl_stmt|;
comment|/* b channel protocol		     */
name|int
name|driver
decl_stmt|;
comment|/* driver to route b channel data to */
name|int
name|driver_unit
decl_stmt|;
comment|/*      unit number for above driver */
name|msg_shorthold_t
name|shorthold_data
decl_stmt|;
comment|/* the shorthold data		     */
name|int
name|unitlen_method
decl_stmt|;
comment|/* how to calculate the unitlength   */
define|#
directive|define
name|ULEN_METHOD_STATIC
value|0
comment|/* use unitlen_time value (see above) */
define|#
directive|define
name|ULEN_METHOD_DYNAMIC
value|1
comment|/* use AOCD */
name|char
name|dst_telno
index|[
name|TELNO_MAX
index|]
decl_stmt|;
comment|/* destination telephone no  */
name|char
name|src_telno
index|[
name|TELNO_MAX
index|]
decl_stmt|;
comment|/* source telephone number   */
block|}
name|msg_connect_req_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I4B_CONNECT_REQ
value|_IOW('4', 1, msg_connect_req_t)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	connect response  *		this is the answer to an incoming connect indication  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|cdid
decl_stmt|;
comment|/* call descriptor id			*/
name|int
name|response
decl_stmt|;
comment|/* what to do with incoming call	*/
define|#
directive|define
name|SETUP_RESP_DNTCRE
value|0
comment|/* dont care, call is not for me	*/
define|#
directive|define
name|SETUP_RESP_REJECT
value|1
comment|/* reject call				*/
define|#
directive|define
name|SETUP_RESP_ACCEPT
value|2
comment|/* accept call				*/
name|cause_t
name|cause
decl_stmt|;
comment|/* cause for case SETUP_RESP_REJECT	*/
comment|/* the following are only used for SETUP_RESP_ACCEPT !! */
name|int
name|txdelay
decl_stmt|;
comment|/* tx delay after connect		*/
name|int
name|bprot
decl_stmt|;
comment|/* B chan protocol			*/
name|int
name|driver
decl_stmt|;
comment|/* driver to route b channel data to	*/
name|int
name|driver_unit
decl_stmt|;
comment|/*      unit number for above driver	*/
name|int
name|max_idle_time
decl_stmt|;
comment|/* max time without activity on b ch	*/
block|}
name|msg_connect_resp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I4B_CONNECT_RESP
value|_IOW('4', 2, msg_connect_resp_t)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	disconnect request  *		active disconnect request  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|cdid
decl_stmt|;
comment|/* call descriptor id			*/
name|cause_t
name|cause
decl_stmt|;
comment|/* protocol independent cause		*/
block|}
name|msg_discon_req_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I4B_DISCONNECT_REQ
value|_IOW('4', 3, msg_discon_req_t)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	controller info request  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|controller
decl_stmt|;
comment|/* controller number			*/
name|int
name|ncontroller
decl_stmt|;
comment|/* number of controllers in system	*/
name|int
name|ctrl_type
decl_stmt|;
comment|/* controller type passive/active	*/
name|int
name|card_type
decl_stmt|;
comment|/* brand / version			*/
name|int
name|tei
decl_stmt|;
comment|/* tei controller probably has		*/
name|int
name|nbch
decl_stmt|;
comment|/* number of b channels provided        */
block|}
name|msg_ctrl_info_req_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I4B_CTRL_INFO_REQ
value|_IOWR('4', 4, msg_ctrl_info_req_t)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	dialout response  *		status report to driver who requested a dialout  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|driver
decl_stmt|;
comment|/* driver to route b channel data to */
name|int
name|driver_unit
decl_stmt|;
comment|/*      unit number for above driver */
name|int
name|stat
decl_stmt|;
comment|/* state of dialout request	     */
define|#
directive|define
name|DSTAT_NONE
value|0
define|#
directive|define
name|DSTAT_TFAIL
value|1
comment|/* transient failure */
define|#
directive|define
name|DSTAT_PFAIL
value|2
comment|/* permanent failure */
define|#
directive|define
name|DSTAT_INONLY
value|3
comment|/* no outgoing dials allowed */
name|cause_t
name|cause
decl_stmt|;
comment|/* exact i4b cause */
block|}
name|msg_dialout_resp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I4B_DIALOUT_RESP
value|_IOW('4', 5, msg_dialout_resp_t)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	timeout value update  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|cdid
decl_stmt|;
comment|/* call descriptor id			*/
name|msg_shorthold_t
name|shorthold_data
decl_stmt|;
block|}
name|msg_timeout_upd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I4B_TIMEOUT_UPD
value|_IOW('4', 6, msg_timeout_upd_t)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	soft enable/disable  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|driver
decl_stmt|;
comment|/* driver to route b channel data to */
name|int
name|driver_unit
decl_stmt|;
comment|/*      unit number for above driver */
name|int
name|updown
decl_stmt|;
comment|/* what to do			     */
define|#
directive|define
name|SOFT_ENA
value|0
comment|/* enable interface */
define|#
directive|define
name|SOFT_DIS
value|1
comment|/* disable interface */
block|}
name|msg_updown_ind_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I4B_UPDOWN_IND
value|_IOW('4', 7, msg_updown_ind_t)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	send alert request  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|cdid
decl_stmt|;
comment|/* call descriptor id			*/
block|}
name|msg_alert_req_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I4B_ALERT_REQ
value|_IOW('4', 8, msg_alert_req_t)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	request version and release info from kernel part  *	(msg_vr_req_t is also used by tel& rbch drivers)  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|version
decl_stmt|;
comment|/* version number */
name|int
name|release
decl_stmt|;
comment|/* release number */
name|int
name|step
decl_stmt|;
comment|/* release step number */
block|}
name|msg_vr_req_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I4B_VR_REQ
value|_IOR('4', 9, msg_vr_req_t)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	set ISDN protocol used by a controller  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|controller
decl_stmt|;
comment|/* controller number		*/
name|int
name|protocol
decl_stmt|;
comment|/* ISDN D-channel protocol type	*/
block|}
name|msg_prot_ind_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I4B_PROT_IND
value|_IOW('4', 10, msg_prot_ind_t)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	Protocol download to active cards  *---------------------------------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|isdn_dr_prot
block|{
name|size_t
name|bytecount
decl_stmt|;
comment|/* length of code */
name|u_int8_t
modifier|*
name|microcode
decl_stmt|;
comment|/* pointer to microcode */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|isdn_download_request
block|{
name|int
name|controller
decl_stmt|;
comment|/* controller number */
name|int
name|numprotos
decl_stmt|;
comment|/* number of protocols in 'protocols' */
name|struct
name|isdn_dr_prot
modifier|*
name|protocols
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I4B_CTRL_DOWNLOAD
value|_IOW('4', 100, struct isdn_download_request)
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	Generic diagnostic interface for active cards  *---------------------------------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|isdn_diagnostic_request
block|{
name|int
name|controller
decl_stmt|;
comment|/* controller number */
name|u_int32_t
name|cmd
decl_stmt|;
comment|/* diagnostic command to execute */
name|size_t
name|in_param_len
decl_stmt|;
comment|/* length of additional input parameter */
define|#
directive|define
name|I4B_ACTIVE_DIAGNOSTIC_MAXPARAMLEN
value|65536
name|void
modifier|*
name|in_param
decl_stmt|;
comment|/* optional input parameter */
name|size_t
name|out_param_len
decl_stmt|;
comment|/* available output space */
name|void
modifier|*
name|out_param
decl_stmt|;
comment|/* output data goes here */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I4B_ACTIVE_DIAGNOSTIC
value|_IOW('4', 102, struct isdn_diagnostic_request)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_IOCTL_H_ */
end_comment

end_unit

