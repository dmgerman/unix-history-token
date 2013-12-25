begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Paolo Pisati<piso@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Alias_mod.h defines the outside world interfaces for the packet aliasing  * modular framework  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIAS_MOD_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALIAS_MOD_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ALIAS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Use kernel allocator. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_SYS_MALLOC_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|malloc
parameter_list|(
name|x
parameter_list|)
value|malloc(x, M_ALIAS, M_NOWAIT|M_ZERO)
end_define

begin_define
define|#
directive|define
name|calloc
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|malloc(x*n)
end_define

begin_define
define|#
directive|define
name|free
parameter_list|(
name|x
parameter_list|)
value|free(x, M_ALIAS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Packet flow direction flags. */
end_comment

begin_define
define|#
directive|define
name|IN
value|0x0001
end_define

begin_define
define|#
directive|define
name|OUT
value|0x0002
end_define

begin_define
define|#
directive|define
name|NODIR
value|0x4000
end_define

begin_comment
comment|/* Working protocol flags. */
end_comment

begin_define
define|#
directive|define
name|IP
value|0x01
end_define

begin_define
define|#
directive|define
name|TCP
value|0x02
end_define

begin_define
define|#
directive|define
name|UDP
value|0x04
end_define

begin_comment
comment|/*  * Data passed to protocol handler module, it must be filled  * right before calling find_handler() to determine which  * module is elegible to be called.  */
end_comment

begin_struct
struct|struct
name|alias_data
block|{
name|struct
name|alias_link
modifier|*
name|lnk
decl_stmt|;
name|struct
name|in_addr
modifier|*
name|oaddr
decl_stmt|;
comment|/* Original address. */
name|struct
name|in_addr
modifier|*
name|aaddr
decl_stmt|;
comment|/* Alias address. */
name|uint16_t
modifier|*
name|aport
decl_stmt|;
comment|/* Alias port. */
name|uint16_t
modifier|*
name|sport
decl_stmt|,
modifier|*
name|dport
decl_stmt|;
comment|/* Source& destination port */
name|uint16_t
name|maxpktsize
decl_stmt|;
comment|/* Max packet size. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure contains all the information necessary to make  * a protocol handler correctly work.  */
end_comment

begin_struct
struct|struct
name|proto_handler
block|{
name|u_int
name|pri
decl_stmt|;
comment|/* Handler priority. */
name|int16_t
name|dir
decl_stmt|;
comment|/* Flow direction. */
name|uint8_t
name|proto
decl_stmt|;
comment|/* Working protocol. */
comment|/* Fingerprint * function. */
name|int
function_decl|(
modifier|*
name|fingerprint
function_decl|)
parameter_list|(
name|struct
name|libalias
modifier|*
parameter_list|,
name|struct
name|alias_data
modifier|*
parameter_list|)
function_decl|;
comment|/* Aliasing * function. */
name|int
function_decl|(
modifier|*
name|protohandler
function_decl|)
parameter_list|(
name|struct
name|libalias
modifier|*
parameter_list|,
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_data
modifier|*
parameter_list|)
function_decl|;
name|TAILQ_ENTRY
argument_list|(
argument|proto_handler
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* End of handlers. */
end_comment

begin_define
define|#
directive|define
name|EOH
value|.dir = NODIR
end_define

begin_comment
comment|/* Functions used with protocol handlers. */
end_comment

begin_function_decl
name|int
name|LibAliasAttachHandlers
parameter_list|(
name|struct
name|proto_handler
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|LibAliasDetachHandlers
parameter_list|(
name|struct
name|proto_handler
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_handler
parameter_list|(
name|int8_t
parameter_list|,
name|int8_t
parameter_list|,
name|struct
name|libalias
modifier|*
parameter_list|,
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|proto_handler
modifier|*
name|first_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/*  * Used only in userland when libalias needs to keep track of all  * module loaded. In kernel land (kld mode) we don't need to care  * care about libalias modules cause it's kld to do it for us.  */
end_comment

begin_define
define|#
directive|define
name|DLL_LEN
value|32
end_define

begin_struct
struct|struct
name|dll
block|{
name|char
name|name
index|[
name|DLL_LEN
index|]
decl_stmt|;
comment|/* Name of module. */
name|void
modifier|*
name|handle
decl_stmt|;
comment|/* 				 * Ptr to shared obj obtained through 				 * dlopen() - use this ptr to get access 				 * to any symbols from a loaded module 				 * via dlsym(). 				 */
name|SLIST_ENTRY
argument_list|(
argument|dll
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Functions used with dll module. */
end_comment

begin_function_decl
name|void
name|dll_chain_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dll_chain_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|attach_dll
parameter_list|(
name|struct
name|dll
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|detach_dll
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|dll
modifier|*
name|walk_dll_chain
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Some defines borrowed from sys/module.h used to compile a kld  * in userland as a shared lib.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|modeventtype
block|{
name|MOD_LOAD
block|,
name|MOD_UNLOAD
block|,
name|MOD_SHUTDOWN
block|,
name|MOD_QUIESCE
block|}
name|modeventtype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|module
modifier|*
name|module_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|modeventhand_t
function_decl|)
parameter_list|(
name|module_t
parameter_list|,
name|int
comment|/* modeventtype_t */
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Struct for registering modules statically via SYSINIT.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|moduledata
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* module name */
name|modeventhand_t
name|evhand
decl_stmt|;
comment|/* event handler */
name|void
modifier|*
name|priv
decl_stmt|;
comment|/* extra data */
block|}
name|moduledata_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ALIAS_MOD_H_ */
end_comment

end_unit

