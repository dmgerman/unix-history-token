begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  ** Copyright (c) 1995  **      Michael Smith, msmith@freebsd.org.  All rights reserved.  **  ** This code contains a module marked :   * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  * Copyright (c) 1994 Jordan K. Hubbard  * All rights reserved.  * Copyright (c) 1994 David Greenman  * All rights reserved.  *  * Many additional changes by Bruce Evans  *  * This code is derived from software contributed by the  * University of California Berkeley, Jordan K. Hubbard,  * David Greenman and Bruce Evans.   ** As such, it contains code subject to the above copyrights.  ** The module and its copyright can be found below.  **   ** Redistribution and use in source and binary forms, with or without  ** modification, are permitted provided that the following conditions  ** are met:  ** 1. Redistributions of source code must retain the above copyright  **    notice, this list of conditions and the following disclaimer as  **    the first lines of this file unmodified.  ** 2. Redistributions in binary form must reproduce the above copyright  **    notice, this list of conditions and the following disclaimer in the  **    documentation and/or other materials provided with the distribution.  ** 3. All advertising materials mentioning features or use of this software  **    must display the following acknowledgment:  **      This product includes software developed by Michael Smith.  ** 4. The name of the author may not be used to endorse or promote products  **    derived from this software without specific prior written permission.  **  ** THIS SOFTWARE IS PROVIDED BY MICHAEL SMITH ``AS IS'' AND ANY EXPRESS OR  ** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  ** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  ** IN NO EVENT SHALL MICHAEL SMITH BE LIABLE FOR ANY DIRECT, INDIRECT,  ** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  ** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  ** THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  **  ** $FreeBSD$  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_MACHINE_UC_DEVICE_H
end_ifndef

begin_define
define|#
directive|define
name|_I386_MACHINE_UC_DEVICE_H
end_define

begin_comment
comment|/*  * Per device structure.  This just happens to resemble the old isa_device  * but that is by accident.  It is NOT the same.  */
end_comment

begin_struct
struct|struct
name|uc_device
block|{
name|int
name|id_id
decl_stmt|;
comment|/* device id */
name|char
modifier|*
name|id_name
decl_stmt|;
comment|/* device name */
name|int
name|id_iobase
decl_stmt|;
comment|/* base i/o address */
name|u_int
name|id_irq
decl_stmt|;
comment|/* interrupt request */
name|int
name|id_drq
decl_stmt|;
comment|/* DMA request */
name|caddr_t
name|id_maddr
decl_stmt|;
comment|/* physical i/o memory address on bus (if any)*/
name|int
name|id_msize
decl_stmt|;
comment|/* size of i/o memory */
name|int
name|id_unit
decl_stmt|;
comment|/* unit number */
name|int
name|id_flags
decl_stmt|;
comment|/* flags */
name|int
name|id_enabled
decl_stmt|;
comment|/* is device enabled */
name|struct
name|uc_device
modifier|*
name|id_next
decl_stmt|;
comment|/* used in uc_devlist in userconfig() */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

