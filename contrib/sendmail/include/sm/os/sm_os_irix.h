begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: sm_os_irix.h,v 1.7 2001/10/09 23:12:13 ca Exp $  */
end_comment

begin_comment
comment|/* **  Silicon Graphics IRIX ** **	Compiles on 4.0.1. ** **	Use IRIX64 instead of IRIX for 64-bit IRIX (6.0). **	Use IRIX5 instead of IRIX for IRIX 5.x. ** **	This version tries to be adaptive using _MIPS_SIM: **		_MIPS_SIM == _ABIO32 (= 1)    Abi: -32 on IRIX 6.2 **		_MIPS_SIM == _ABIN32 (= 2)    Abi: -n32 on IRIX 6.2 **		_MIPS_SIM == _ABI64  (= 3)    Abi: -64 on IRIX 6.2 ** **		_MIPS_SIM is 1 also on IRIX 5.3 ** **	IRIX64 changes from Mark R. Levinson<ml@cvdev.rochester.edu>. **	IRIX5 changes from Kari E. Hurtta<Kari.Hurtta@fmi.fi>. **	Adaptive changes from Kari E. Hurtta<Kari.Hurtta@fmi.fi>. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IRIX
end_ifndef

begin_define
define|#
directive|define
name|IRIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! IRIX */
end_comment

begin_if
if|#
directive|if
name|_MIPS_SIM
operator|>
literal|0
operator|&&
operator|!
name|defined
argument_list|(
name|IRIX5
argument_list|)
end_if

begin_define
define|#
directive|define
name|IRIX5
end_define

begin_comment
comment|/* IRIX5 or IRIX6 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_SIM> 0&& !defined(IRIX5) */
end_comment

begin_if
if|#
directive|if
name|_MIPS_SIM
operator|>
literal|1
operator|&&
operator|!
name|defined
argument_list|(
name|IRIX6
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|IRIX64
argument_list|)
end_if

begin_define
define|#
directive|define
name|IRIX6
end_define

begin_comment
comment|/* IRIX6 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_SIM> 1&& !defined(IRIX6)&& !defined(IRIX64) */
end_comment

begin_define
define|#
directive|define
name|SM_OS_NAME
value|"irix"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IRIX6
argument_list|)
operator|||
name|defined
argument_list|(
name|IRIX64
argument_list|)
end_if

begin_define
define|#
directive|define
name|SM_CONF_LONGLONG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(IRIX6) || defined(IRIX64) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IRIX64
argument_list|)
operator|||
name|defined
argument_list|(
name|IRIX5
argument_list|)
operator|||
name|defined
argument_list|(
name|IRIX6
argument_list|)
end_if

begin_define
define|#
directive|define
name|SM_CONF_SYS_CDEFS_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(IRIX64) || defined(IRIX5) || defined(IRIX6) */
end_comment

begin_comment
comment|/* try LLONG tests in libsm/t-types.c? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_CONF_TEST_LLONG
end_ifndef

begin_define
define|#
directive|define
name|SM_CONF_TEST_LLONG
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SM_CONF_TEST_LLONG */
end_comment

end_unit

