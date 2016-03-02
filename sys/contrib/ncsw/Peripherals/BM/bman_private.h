begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************   © 1995-2003, 2004, 2005-2011 Freescale Semiconductor, Inc.  All rights reserved.   This is proprietary source code of Freescale Semiconductor Inc.,  and its use is subject to the NetComm Device Drivers EULA.  The copyright notice above does not evidence any actual or intended  publication of such source code.   ALTERNATIVELY, redistribution and use in source and binary forms, with  or without modification, are permitted provided that the following  conditions are met:      * Redistributions of source code must retain the above copyright        notice, this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.      * Neither the name of Freescale Semiconductor nor the        names of its contributors may be used to endorse or promote products        derived from this software without specific prior written permission.   THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   **************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  @File          bman_private.h   @Description   BM header */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BMAN_PRIV_H
end_ifndef

begin_define
define|#
directive|define
name|__BMAN_PRIV_H
end_define

begin_include
include|#
directive|include
file|"fsl_bman.h"
end_include

begin_define
define|#
directive|define
name|__ERR_MODULE__
value|MODULE_BM
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUG
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|DISABLE_ASSERTIONS
argument_list|)
end_if

begin_comment
comment|/* Optionally compile-in assertion-checking */
end_comment

begin_define
define|#
directive|define
name|BM_CHECKING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(DEBUG) || ... */
end_comment

begin_comment
comment|/* TODO: NB, we currently assume that CORE_MemoryBarier() and lwsync() imply compiler barriers  * and that dcbzl(), dcbfl(), and dcbi() won't fall victim to compiler or  * execution reordering with respect to other code/instructions that manipulate  * the same cacheline. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CORE_E500MC
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_DIAB_TOOL
argument_list|)
end_if

begin_define
define|#
directive|define
name|hwsync
parameter_list|()
define|\
value|do { \ __asm__ __volatile__ ("sync"); \ } while(0)
end_define

begin_define
define|#
directive|define
name|lwsync
parameter_list|()
define|\
value|do { \ __asm__ __volatile__ ("lwsync"); \ } while(0)
end_define

begin_function
name|__asm__
specifier|__volatile__
name|void
name|dcbf
parameter_list|(
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
operator|%
name|reg
name|addr
name|dcbf
name|r0
operator|,
name|addr
block|}
end_function

begin_function
name|__asm__
specifier|__volatile__
name|void
name|dcbt_ro
parameter_list|(
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
operator|%
name|reg
name|addr
name|dcbt
name|r0
operator|,
name|addr
block|}
end_function

begin_function
name|__asm__
specifier|__volatile__
name|void
name|dcbt_rw
parameter_list|(
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
operator|%
name|reg
name|addr
name|dcbtst
name|r0
operator|,
name|addr
block|}
end_function

begin_function
name|__asm__
specifier|__volatile__
name|void
name|dcbzl
parameter_list|(
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
operator|%
name|reg
name|addr
name|dcbzl
name|r0
operator|,
name|addr
block|}
end_function

begin_define
define|#
directive|define
name|dcbz_64
parameter_list|(
name|p
parameter_list|)
define|\
value|do { \         dcbzl(p); \     } while (0)
end_define

begin_define
define|#
directive|define
name|dcbf_64
parameter_list|(
name|p
parameter_list|)
define|\
value|do { \         dcbf(p); \     } while (0)
end_define

begin_comment
comment|/* Commonly used combo */
end_comment

begin_define
define|#
directive|define
name|dcbit_ro
parameter_list|(
name|p
parameter_list|)
define|\
value|do { \         dcbi(p); \         dcbt_ro(p); \     } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* GNU C */
end_comment

begin_define
define|#
directive|define
name|hwsync
parameter_list|()
define|\
value|do { \         __asm__ __volatile__ ("sync" : : : "memory"); \     } while(0)
end_define

begin_define
define|#
directive|define
name|lwsync
parameter_list|()
define|\
value|do { \         __asm__ __volatile__ ("lwsync" : : : "memory"); \     } while(0)
end_define

begin_define
define|#
directive|define
name|dcbf
parameter_list|(
name|addr
parameter_list|)
define|\
value|do { \         __asm__ __volatile__ ("dcbf 0, %0" : : "r" (addr)); \     } while(0)
end_define

begin_define
define|#
directive|define
name|dcbt_ro
parameter_list|(
name|addr
parameter_list|)
define|\
value|do { \         __asm__ __volatile__ ("dcbt 0, %0" : : "r" (addr)); \     } while(0)
end_define

begin_define
define|#
directive|define
name|dcbt_rw
parameter_list|(
name|addr
parameter_list|)
define|\
value|do { \         __asm__ __volatile__ ("dcbtst 0, %0" : : "r" (addr)); \     } while(0)
end_define

begin_define
define|#
directive|define
name|dcbzl
parameter_list|(
name|p
parameter_list|)
define|\
value|do { \         __asm__ __volatile__ ("dcbzl 0,%0" : : "r" (p)); \     } while(0)
end_define

begin_define
define|#
directive|define
name|dcbz_64
parameter_list|(
name|p
parameter_list|)
define|\
value|do { \         dcbzl(p); \     } while (0)
end_define

begin_define
define|#
directive|define
name|dcbf_64
parameter_list|(
name|p
parameter_list|)
define|\
value|do { \         dcbf(p); \     } while (0)
end_define

begin_comment
comment|/* Commonly used combo */
end_comment

begin_define
define|#
directive|define
name|dcbit_ro
parameter_list|(
name|p
parameter_list|)
define|\
value|do { \         dcbi(p); \         dcbt_ro(p); \     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DIAB_TOOL */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|hwsync
value|CORE_MemoryBarrier
end_define

begin_define
define|#
directive|define
name|lwsync
value|hwsync
end_define

begin_define
define|#
directive|define
name|dcbf
parameter_list|(
name|p
parameter_list|)
define|\
value|do { \         __asm__ __volatile__ ("dcbf 0,%0" : : "r" (p)); \     } while(0)
end_define

begin_define
define|#
directive|define
name|dcbt_ro
parameter_list|(
name|p
parameter_list|)
define|\
value|do { \         __asm__ __volatile__ ("dcbt 0,%0" : : "r" (p)); \         lwsync(); \     } while(0)
end_define

begin_define
define|#
directive|define
name|dcbt_rw
parameter_list|(
name|p
parameter_list|)
define|\
value|do { \         __asm__ __volatile__ ("dcbtst 0,%0" : : "r" (p)); \     } while(0)
end_define

begin_define
define|#
directive|define
name|dcbz
parameter_list|(
name|p
parameter_list|)
define|\
value|do { \         __asm__ __volatile__ ("dcbz 0,%0" : : "r" (p)); \     } while (0)
end_define

begin_define
define|#
directive|define
name|dcbz_64
parameter_list|(
name|p
parameter_list|)
define|\
value|do { \         dcbz((uint32_t)p + 32); \         dcbz(p);    \     } while (0)
end_define

begin_define
define|#
directive|define
name|dcbf_64
parameter_list|(
name|p
parameter_list|)
define|\
value|do { \         dcbf((uint32_t)p + 32); \         dcbf(p); \     } while (0)
end_define

begin_comment
comment|/* Commonly used combo */
end_comment

begin_define
define|#
directive|define
name|dcbit_ro
parameter_list|(
name|p
parameter_list|)
define|\
value|do { \         dcbi(p); \         dcbi((uint32_t)p + 32); \         dcbt_ro(p); \         dcbt_ro((uint32_t)p + 32); \     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CORE_E500MC */
end_comment

begin_define
define|#
directive|define
name|dcbi
parameter_list|(
name|p
parameter_list|)
value|dcbf(p)
end_define

begin_struct
struct|struct
name|bm_addr
block|{
name|void
modifier|*
name|addr_ce
decl_stmt|;
comment|/* cache-enabled */
name|void
modifier|*
name|addr_ci
decl_stmt|;
comment|/* cache-inhibited */
block|}
struct|;
end_struct

begin_comment
comment|/* RCR state */
end_comment

begin_struct
struct|struct
name|bm_rcr
block|{
name|struct
name|bm_rcr_entry
modifier|*
name|ring
decl_stmt|,
modifier|*
name|cursor
decl_stmt|;
name|uint8_t
name|ci
decl_stmt|,
name|available
decl_stmt|,
name|ithresh
decl_stmt|,
name|vbit
decl_stmt|;
ifdef|#
directive|ifdef
name|BM_CHECKING
name|uint32_t
name|busy
decl_stmt|;
name|e_BmPortalProduceMode
name|pmode
decl_stmt|;
name|e_BmPortalRcrConsumeMode
name|cmode
decl_stmt|;
endif|#
directive|endif
comment|/* BM_CHECKING */
block|}
struct|;
end_struct

begin_comment
comment|/* MC state */
end_comment

begin_struct
struct|struct
name|bm_mc
block|{
name|struct
name|bm_mc_command
modifier|*
name|cr
decl_stmt|;
name|struct
name|bm_mc_result
modifier|*
name|rr
decl_stmt|;
name|uint8_t
name|rridx
decl_stmt|,
name|vbit
decl_stmt|;
ifdef|#
directive|ifdef
name|BM_CHECKING
enum|enum
block|{
comment|/* Can only be _mc_start()ed */
name|mc_idle
block|,
comment|/* Can only be _mc_commit()ed or _mc_abort()ed */
name|mc_user
block|,
comment|/* Can only be _mc_retry()ed */
name|mc_hw
block|}
name|state
enum|;
endif|#
directive|endif
comment|/* BM_CHECKING */
block|}
struct|;
end_struct

begin_comment
comment|/********************/
end_comment

begin_comment
comment|/* Portal structure */
end_comment

begin_comment
comment|/********************/
end_comment

begin_struct
struct|struct
name|bm_portal
block|{
name|struct
name|bm_addr
name|addr
decl_stmt|;
name|struct
name|bm_rcr
name|rcr
decl_stmt|;
name|struct
name|bm_mc
name|mc
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BMAN_PRIV_H */
end_comment

end_unit

