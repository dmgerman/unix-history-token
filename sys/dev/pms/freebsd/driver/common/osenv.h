begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * *******************************************************************************/
end_comment

begin_comment
comment|/***************************************************************************  Version Control Information:   $RCSfile: osenv.h,v $ $Revision: 114125 $  Note:  This file defines the working environment of the system.  All        defines listed in this file could also be compiler flags.        I am listing all the defines (even if used as a compiler flag)        so that they can be seen and documented. ***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OSENV_H__
end_ifndef

begin_define
define|#
directive|define
name|__OSENV_H__
end_define

begin_include
include|#
directive|include
file|<dev/pms/freebsd/driver/common/osstring.h>
end_include

begin_comment
comment|/*  ** Define the protocols to compile with.  Currently, these defines are ** only for this header file and are used further down to define the protocol ** specific environment: ** **      #define AG_PROTOCOL_ISCSI **      #define AG_PROTOCOL_FC */
end_comment

begin_comment
comment|/*  ** Define the application types: ** **      #define INITIATOR_DRIVER **      #define TARGET_DRIVER */
end_comment

begin_comment
comment|/*  ** Define the endian-ness of the host CPU using one of the following: ** **      #define AG_CPU_LITTLE_ENDIAN **      #define AG_CPU_BIG_ENDIAN */
end_comment

begin_comment
comment|/* ** Define the host CPU word size  ** **      #define AG_CPU_32_BIT **      #define AG_CPU_64_BIT ** */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_IA64
end_ifdef

begin_define
define|#
directive|define
name|AG_CPU_64_BIT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AG_CPU_32_BIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ** The following allow the code to use defines for word alignment and adding ** to allow for 32bit and 64bit system differences. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AG_CPU_32_BIT
end_ifdef

begin_define
define|#
directive|define
name|AG_WORD_ALIGN_ADD
value|3
end_define

begin_define
define|#
directive|define
name|AG_WORD_ALIGN_MASK
value|0xfffffffc
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AG_WORD_ALIGN_ADD
value|7
end_define

begin_define
define|#
directive|define
name|AG_WORD_ALIGN_MASK
value|0xfffffff8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*************************************************************************** iSCSI environment - The following is used for compiling the iSCSI                      protocol. **************************************************************************/
end_comment

begin_comment
comment|/* ** Define the existence of an external bus swapper using on of the ** following:  ** **      #define AG_SWAPPING_BUS **      #define AG_NON_SWAPPING_BUS ** */
end_comment

begin_comment
comment|/* ** Define the use of cache memory for message system:  ** **      #define AG_CACHED_MSG_SYSTEM ** */
end_comment

begin_comment
comment|/* #define AG_CACHED_MSG_SYSTEM */
end_comment

begin_comment
comment|/*************************************************************************** FC environment - The following is used for compiling the FC protocol. **************************************************************************/
end_comment

begin_comment
comment|/* ** Define if an PMC-Sierra card is being used:  ** **      #define CCFLAGS_PMC_SIERRA_BOARD ** */
end_comment

begin_comment
comment|/* ** Define if the TSDK is being used:  ** **      #define FCLayer_Tsdk ** */
end_comment

begin_comment
comment|/* ** The following defines are not changed directly, but use either previous ** defines, or compiler directives. ** */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AG_CPU_LITTLE_ENDIAN
end_ifdef

begin_define
define|#
directive|define
name|FC_DMA_LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|FC_CPU_LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|SA_DMA_LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|SA_CPU_LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AG_CPU_BIG_ENDIAN
end_ifdef

begin_define
define|#
directive|define
name|FC_DMA_BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|FC_CPU_BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|SA_DMA_BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|SA_CPU_BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* warning: leave this next line as-is.  it is used for FC-Layer testing      */
end_comment

begin_undef
undef|#
directive|undef
name|FC_CHECKMACRO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OSENV_H__ */
end_comment

end_unit

