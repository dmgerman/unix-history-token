begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Generic driver for the Advanced Systems Inc. SCSI controllers  * Product specific probe and attach routines can be found in:  *   * XXX Fill this in.  *  * Copyright (c) 1996 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ADVANSYS_H_
end_ifndef

begin_define
define|#
directive|define
name|_ADVANSYS_H_
end_define

begin_include
include|#
directive|include
file|"adv.h"
end_include

begin_include
include|#
directive|include
file|<dev/advansys/advlib.h>
end_include

begin_decl_stmt
name|struct
name|adv_softc
modifier|*
name|adv_alloc
name|__P
argument_list|(
operator|(
name|int
name|unit
operator|,
name|u_long
name|iobase
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|adv_free
name|__P
argument_list|(
operator|(
expr|struct
name|adv_softc
operator|*
name|adv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|adv_init
name|__P
argument_list|(
operator|(
expr|struct
name|adv_softc
operator|*
name|adv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|adv_intr
name|__P
argument_list|(
operator|(
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|adv_attach
name|__P
argument_list|(
operator|(
expr|struct
name|adv_softc
operator|*
name|adv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|adv_softc
modifier|*
name|advsoftcs
index|[
name|NADV
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX Config should handle this */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ADVANSYS_H_ */
end_comment

end_unit

