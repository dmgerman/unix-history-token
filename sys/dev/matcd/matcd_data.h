begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*matcd_data.h---------------------------------------------------------------  	Matsushita(Panasonic) / Creative CD-ROM Driver	(matcd) 	Authored by Frank Durda IV  Copyright 1994, 1995, 2002, 2003  Frank Durda IV.  All rights reserved. "FDIV" is a trademark of Frank Durda IV.  ------------------------------------------------------------------------------  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met: 1. Redistributions of source code must retain the above copyright    notice, this list of conditions and the following disclaimer. 2. Redistributions in binary form must reproduce the above copyright    notice, this list of conditions and the following disclaimer in the    documentation and/or other materials provided with the distribution. 3. Neither the name of the author nor the names of their contributors    may be used to endorse or promote products derived from this software    without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  ------------------------------------------------------------------------------  See matcd.c for Edit History */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------- 	Structures common in matcd.c and matcd_isa.c ----------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*	This structure is a creation required by the newer FreeBSD 5.0 bus 	abstraction.  Mainly used by all *_isa_*, attach and probe functions. */
end_comment

begin_struct
struct|struct
name|matcd_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|dev_t
name|matcd_dev_t
decl_stmt|;
name|struct
name|resource
modifier|*
name|port
decl_stmt|;
name|int
name|port_rid
decl_stmt|;
name|int
name|port_type
decl_stmt|;
name|bus_space_tag_t
name|port_bst
decl_stmt|;
name|bus_space_handle_t
name|port_bsh
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*End of matcd_data.h*/
end_comment

end_unit

