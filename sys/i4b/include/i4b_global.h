begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1999 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_global.h - i4b global include file  *	--------------------------------------  *  *	$Id: i4b_global.h,v 1.23 1999/12/13 21:25:24 hm Exp $  *  * $FreeBSD$  *  *	last edit-date: [Mon Dec 13 21:44:17 1999]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_GLOBAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_GLOBAL_H_
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	hiding OS differences in the kernel  *---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*---------------*/
end_comment

begin_comment
comment|/* time handling */
end_comment

begin_comment
comment|/*---------------*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
name|__FreeBSD_version
operator|>=
literal|400000
operator|&&
name|__FreeBSD_version
operator|<
literal|400011
end_if

begin_error
error|#
directive|error
literal|"Unsupported FreeBSD-current version,"
end_error

begin_error
error|#
directive|error
literal|"you need a FreeBSD-current>= 400011"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|&&
name|__FreeBSD_version
operator|>=
literal|300001
end_if

begin_define
define|#
directive|define
name|TIMEOUT_FUNC_T
value|timeout_t *
end_define

begin_define
define|#
directive|define
name|SECOND
value|time_second
end_define

begin_define
define|#
directive|define
name|MICROTIME
parameter_list|(
name|x
parameter_list|)
value|getmicrotime(&(x))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FreeBSD< 3 */
end_comment

begin_define
define|#
directive|define
name|TIMEOUT_FUNC_T
value|timeout_func_t
end_define

begin_define
define|#
directive|define
name|SECOND
value|time.tv_sec
end_define

begin_define
define|#
directive|define
name|MICROTIME
parameter_list|(
name|x
parameter_list|)
value|microtime(&(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*>= 3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
end_if

begin_define
define|#
directive|define
name|TIMEOUT_FUNC_T
value|void *
end_define

begin_define
define|#
directive|define
name|SECOND
value|time.tv_sec
end_define

begin_define
define|#
directive|define
name|MICROTIME
parameter_list|(
name|x
parameter_list|)
value|(x) = time
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_comment
comment|/*----------------------*/
end_comment

begin_comment
comment|/* poll/select handling */
end_comment

begin_comment
comment|/*----------------------*/
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
expr|\
operator|(
operator|!
name|defined
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|||
operator|(
name|__FreeBSD_version
operator|<
literal|300001
operator|)
operator|)
operator|)
expr|\
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
end_if

begin_define
define|#
directive|define
name|OS_USES_SELECT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OS_USES_POLL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------------------------------------------------*  *	misc globally used things in the kernel  *---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* timer states */
end_comment

begin_define
define|#
directive|define
name|TIMER_IDLE
value|1
end_define

begin_comment
comment|/* a timer is running	*/
end_comment

begin_define
define|#
directive|define
name|TIMER_ACTIVE
value|2
end_define

begin_comment
comment|/* a timer is idle	*/
end_comment

begin_comment
comment|/* i4b's spl */
end_comment

begin_define
define|#
directive|define
name|SPLI4B
parameter_list|()
value|splimp()
end_define

begin_comment
comment|/* spl for i4b		*/
end_comment

begin_comment
comment|/* critial code region handling macros */
end_comment

begin_define
define|#
directive|define
name|CRIT_VAR
value|int _svd_spl_
end_define

begin_comment
comment|/* declare variable	*/
end_comment

begin_define
define|#
directive|define
name|CRIT_BEG
value|_svd_spl_ = SPLI4B()
end_define

begin_comment
comment|/* save spl	*/
end_comment

begin_define
define|#
directive|define
name|CRIT_END
value|splx(_svd_spl_)
end_define

begin_comment
comment|/* restore spl		*/
end_comment

begin_comment
comment|/* definitions for the STATUS indications L1 -> L2 -> L3 */
end_comment

begin_define
define|#
directive|define
name|STI_ATTACH
value|0
end_define

begin_comment
comment|/* attach at boot time	*/
end_comment

begin_define
define|#
directive|define
name|STI_L1STAT
value|1
end_define

begin_comment
comment|/* layer 1 status	*/
end_comment

begin_define
define|#
directive|define
name|STI_L2STAT
value|2
end_define

begin_comment
comment|/* layer 2 status	*/
end_comment

begin_define
define|#
directive|define
name|STI_TEIASG
value|3
end_define

begin_comment
comment|/* TEI assignments	*/
end_comment

begin_define
define|#
directive|define
name|STI_PDEACT
value|4
end_define

begin_comment
comment|/* Layer 1 T4 expired = persistent deactivation */
end_comment

begin_define
define|#
directive|define
name|STI_NOL1ACC
value|5
end_define

begin_comment
comment|/* no outgoing L1 access possible */
end_comment

begin_comment
comment|/* definitions for the COMMAND requests L3 -> L2 -> L1 */
end_comment

begin_define
define|#
directive|define
name|CMR_DOPEN
value|0
end_define

begin_comment
comment|/* daemon opened /dev/i4b */
end_comment

begin_define
define|#
directive|define
name|CMR_DCLOSE
value|1
end_define

begin_comment
comment|/* daemon closed /dev/i4b */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------  *  *	Number of max supported passive card units  *  *	Teles/Creatix/Neuhaus cards have a hardware limitation  *	as one is able to set 3 (sometimes 4) different configurations by  *      jumpers so a maximum of 3 (4) cards per ISA bus is possible.  *      (Note: there are multiple ISA buses on some architectures)  *  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|ISIC_MAXUNIT
value|3
end_define

begin_comment
comment|/* max no of supported units 0..3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_GLOBAL_H_ */
end_comment

end_unit

