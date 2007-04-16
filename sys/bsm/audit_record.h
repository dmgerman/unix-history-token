begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Apple Computer, Inc.  * All rights reserved.  *  * @APPLE_BSD_LICENSE_HEADER_START@  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * @APPLE_BSD_LICENSE_HEADER_END@  *  * $P4: //depot/projects/trustedbsd/audit3/sys/bsm/audit_record.h#24 $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSM_AUDIT_RECORD_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSM_AUDIT_RECORD_H_
end_define

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* struct timeval */
end_comment

begin_comment
comment|/*  * Token type identifiers.  */
end_comment

begin_define
define|#
directive|define
name|AUT_INVALID
value|0x00
end_define

begin_define
define|#
directive|define
name|AUT_OTHER_FILE32
value|0x11
end_define

begin_define
define|#
directive|define
name|AUT_OHEADER
value|0x12
end_define

begin_define
define|#
directive|define
name|AUT_TRAILER
value|0x13
end_define

begin_define
define|#
directive|define
name|AUT_HEADER32
value|0x14
end_define

begin_define
define|#
directive|define
name|AUT_HEADER32_EX
value|0x15
end_define

begin_define
define|#
directive|define
name|AUT_DATA
value|0x21
end_define

begin_define
define|#
directive|define
name|AUT_IPC
value|0x22
end_define

begin_define
define|#
directive|define
name|AUT_PATH
value|0x23
end_define

begin_define
define|#
directive|define
name|AUT_SUBJECT32
value|0x24
end_define

begin_define
define|#
directive|define
name|AUT_SERVER32
value|0x25
end_define

begin_define
define|#
directive|define
name|AUT_PROCESS32
value|0x26
end_define

begin_define
define|#
directive|define
name|AUT_RETURN32
value|0x27
end_define

begin_define
define|#
directive|define
name|AUT_TEXT
value|0x28
end_define

begin_define
define|#
directive|define
name|AUT_OPAQUE
value|0x29
end_define

begin_define
define|#
directive|define
name|AUT_IN_ADDR
value|0x2a
end_define

begin_define
define|#
directive|define
name|AUT_IP
value|0x2b
end_define

begin_define
define|#
directive|define
name|AUT_IPORT
value|0x2c
end_define

begin_define
define|#
directive|define
name|AUT_ARG32
value|0x2d
end_define

begin_define
define|#
directive|define
name|AUT_SOCKET
value|0x2e
end_define

begin_define
define|#
directive|define
name|AUT_SEQ
value|0x2f
end_define

begin_define
define|#
directive|define
name|AUT_ACL
value|0x30
end_define

begin_define
define|#
directive|define
name|AUT_ATTR
value|0x31
end_define

begin_define
define|#
directive|define
name|AUT_IPC_PERM
value|0x32
end_define

begin_define
define|#
directive|define
name|AUT_LABEL
value|0x33
end_define

begin_define
define|#
directive|define
name|AUT_GROUPS
value|0x34
end_define

begin_define
define|#
directive|define
name|AUT_ILABEL
value|0x35
end_define

begin_define
define|#
directive|define
name|AUT_SLABEL
value|0x36
end_define

begin_define
define|#
directive|define
name|AUT_CLEAR
value|0x37
end_define

begin_define
define|#
directive|define
name|AUT_PRIV
value|0x38
end_define

begin_define
define|#
directive|define
name|AUT_UPRIV
value|0x39
end_define

begin_define
define|#
directive|define
name|AUT_LIAISON
value|0x3a
end_define

begin_define
define|#
directive|define
name|AUT_NEWGROUPS
value|0x3b
end_define

begin_define
define|#
directive|define
name|AUT_EXEC_ARGS
value|0x3c
end_define

begin_define
define|#
directive|define
name|AUT_EXEC_ENV
value|0x3d
end_define

begin_define
define|#
directive|define
name|AUT_ATTR32
value|0x3e
end_define

begin_comment
comment|/* #define	AUT_????	0x3f */
end_comment

begin_define
define|#
directive|define
name|AUT_XATOM
value|0x40
end_define

begin_define
define|#
directive|define
name|AUT_XOBJ
value|0x41
end_define

begin_define
define|#
directive|define
name|AUT_XPROTO
value|0x42
end_define

begin_define
define|#
directive|define
name|AUT_XSELECT
value|0x43
end_define

begin_comment
comment|/* XXXRW: Additional X11 tokens not defined? */
end_comment

begin_define
define|#
directive|define
name|AUT_CMD
value|0x51
end_define

begin_define
define|#
directive|define
name|AUT_EXIT
value|0x52
end_define

begin_define
define|#
directive|define
name|AUT_ZONENAME
value|0x60
end_define

begin_comment
comment|/* XXXRW: OpenBSM AUT_HOST 0x70? */
end_comment

begin_define
define|#
directive|define
name|AUT_ARG64
value|0x71
end_define

begin_define
define|#
directive|define
name|AUT_RETURN64
value|0x72
end_define

begin_define
define|#
directive|define
name|AUT_ATTR64
value|0x73
end_define

begin_define
define|#
directive|define
name|AUT_HEADER64
value|0x74
end_define

begin_define
define|#
directive|define
name|AUT_SUBJECT64
value|0x75
end_define

begin_define
define|#
directive|define
name|AUT_SERVER64
value|0x76
end_define

begin_define
define|#
directive|define
name|AUT_PROCESS64
value|0x77
end_define

begin_define
define|#
directive|define
name|AUT_OTHER_FILE64
value|0x78
end_define

begin_define
define|#
directive|define
name|AUT_HEADER64_EX
value|0x79
end_define

begin_define
define|#
directive|define
name|AUT_SUBJECT32_EX
value|0x7a
end_define

begin_define
define|#
directive|define
name|AUT_PROCESS32_EX
value|0x7b
end_define

begin_define
define|#
directive|define
name|AUT_SUBJECT64_EX
value|0x7c
end_define

begin_define
define|#
directive|define
name|AUT_PROCESS64_EX
value|0x7d
end_define

begin_define
define|#
directive|define
name|AUT_IN_ADDR_EX
value|0x7e
end_define

begin_define
define|#
directive|define
name|AUT_SOCKET_EX
value|0x7f
end_define

begin_comment
comment|/*  * Pre-64-bit BSM, 32-bit tokens weren't explicitly named as '32'.  We have  * compatibility defines.  */
end_comment

begin_define
define|#
directive|define
name|AUT_HEADER
value|AUT_HEADER32
end_define

begin_define
define|#
directive|define
name|AUT_ARG
value|AUT_ARG32
end_define

begin_define
define|#
directive|define
name|AUT_RETURN
value|AUT_RETURN32
end_define

begin_define
define|#
directive|define
name|AUT_SUBJECT
value|AUT_SUBJECT32
end_define

begin_define
define|#
directive|define
name|AUT_SERVER
value|AUT_SERVER32
end_define

begin_define
define|#
directive|define
name|AUT_PROCESS
value|AUT_PROCESS32
end_define

begin_define
define|#
directive|define
name|AUT_OTHER_FILE
value|AUT_OTHER_FILE32
end_define

begin_comment
comment|/*  * Darwin's bsm distribution uses the following non-BSM token name defines.  * We provide them for a single OpenBSM release for compatibility reasons.  */
end_comment

begin_define
define|#
directive|define
name|AU_FILE_TOKEN
value|AUT_OTHER_FILE32
end_define

begin_define
define|#
directive|define
name|AU_TRAILER_TOKEN
value|AUT_TRAILER
end_define

begin_define
define|#
directive|define
name|AU_HEADER_32_TOKEN
value|AUT_HEADER32
end_define

begin_define
define|#
directive|define
name|AU_DATA_TOKEN
value|AUT_DATA
end_define

begin_define
define|#
directive|define
name|AU_ARB_TOKEN
value|AUT_DATA
end_define

begin_define
define|#
directive|define
name|AU_IPC_TOKEN
value|AUT_IPC
end_define

begin_define
define|#
directive|define
name|AU_PATH_TOKEN
value|AUT_PATH
end_define

begin_define
define|#
directive|define
name|AU_SUBJECT_32_TOKEN
value|AUT_SUBJECT32
end_define

begin_define
define|#
directive|define
name|AU_PROCESS_32_TOKEN
value|AUT_PROCESS32
end_define

begin_define
define|#
directive|define
name|AU_RETURN_32_TOKEN
value|AUT_RETURN32
end_define

begin_define
define|#
directive|define
name|AU_TEXT_TOKEN
value|AUT_TEXT
end_define

begin_define
define|#
directive|define
name|AU_OPAQUE_TOKEN
value|AUT_OPAQUE
end_define

begin_define
define|#
directive|define
name|AU_IN_ADDR_TOKEN
value|AUT_IN_ADDR
end_define

begin_define
define|#
directive|define
name|AU_IP_TOKEN
value|AUT_IP
end_define

begin_define
define|#
directive|define
name|AU_IPORT_TOKEN
value|AUT_IPORT
end_define

begin_define
define|#
directive|define
name|AU_ARG32_TOKEN
value|AUT_ARG32
end_define

begin_define
define|#
directive|define
name|AU_SOCK_TOKEN
value|AUT_SOCKET
end_define

begin_define
define|#
directive|define
name|AU_SEQ_TOKEN
value|AUT_SEQ
end_define

begin_define
define|#
directive|define
name|AU_ATTR_TOKEN
value|AUT_ATTR
end_define

begin_define
define|#
directive|define
name|AU_IPCPERM_TOKEN
value|AUT_IPC_PERM
end_define

begin_define
define|#
directive|define
name|AU_NEWGROUPS_TOKEN
value|AUT_NEWGROUPS
end_define

begin_define
define|#
directive|define
name|AU_EXEC_ARG_TOKEN
value|AUT_EXEC_ARGS
end_define

begin_define
define|#
directive|define
name|AU_EXEC_ENV_TOKEN
value|AUT_EXEC_ENV
end_define

begin_define
define|#
directive|define
name|AU_ATTR32_TOKEN
value|AUT_ATTR32
end_define

begin_define
define|#
directive|define
name|AU_CMD_TOKEN
value|AUT_CMD
end_define

begin_define
define|#
directive|define
name|AU_EXIT_TOKEN
value|AUT_EXIT
end_define

begin_define
define|#
directive|define
name|AU_ARG64_TOKEN
value|AUT_ARG64
end_define

begin_define
define|#
directive|define
name|AU_RETURN_64_TOKEN
value|AUT_RETURN64
end_define

begin_define
define|#
directive|define
name|AU_ATTR64_TOKEN
value|AUT_ATTR64
end_define

begin_define
define|#
directive|define
name|AU_HEADER_64_TOKEN
value|AUT_HEADER64
end_define

begin_define
define|#
directive|define
name|AU_SUBJECT_64_TOKEN
value|AUT_SUBJECT64
end_define

begin_define
define|#
directive|define
name|AU_PROCESS_64_TOKEN
value|AUT_PROCESS64
end_define

begin_define
define|#
directive|define
name|AU_HEADER_64_EX_TOKEN
value|AUT_HEADER64_EX
end_define

begin_define
define|#
directive|define
name|AU_SUBJECT_32_EX_TOKEN
value|AUT_SUBJECT32_EX
end_define

begin_define
define|#
directive|define
name|AU_PROCESS_32_EX_TOKEN
value|AUT_PROCESS32_EX
end_define

begin_define
define|#
directive|define
name|AU_SUBJECT_64_EX_TOKEN
value|AUT_SUBJECT64_EX
end_define

begin_define
define|#
directive|define
name|AU_PROCESS_64_EX_TOKEN
value|AUT_PROCESS64_EX
end_define

begin_define
define|#
directive|define
name|AU_IN_ADDR_EX_TOKEN
value|AUT_IN_ADDR_EX
end_define

begin_define
define|#
directive|define
name|AU_SOCK_32_EX_TOKEN
value|AUT_SOCKET_EX
end_define

begin_comment
comment|/*  * The values for the following token ids are not defined by BSM.  *  * XXXRW: Not sure how to handle these in OpenBSM yet, but I'll give them  * names more consistent with Sun's BSM.  These originally came from Apple's  * BSM.  */
end_comment

begin_define
define|#
directive|define
name|AUT_SOCKINET32
value|0x80
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|AUT_SOCKINET128
value|0x81
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|AUT_SOCKUNIX
value|0x82
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|AU_SOCK_INET_32_TOKEN
value|AUT_SOCKINET32
end_define

begin_define
define|#
directive|define
name|AU_SOCK_INET_128_TOKEN
value|AUT_SOCKINET128
end_define

begin_define
define|#
directive|define
name|AU_SOCK_UNIX_TOKEN
value|AUT_SOCKUNIX
end_define

begin_comment
comment|/* print values for the arbitrary token */
end_comment

begin_define
define|#
directive|define
name|AUP_BINARY
value|0
end_define

begin_define
define|#
directive|define
name|AUP_OCTAL
value|1
end_define

begin_define
define|#
directive|define
name|AUP_DECIMAL
value|2
end_define

begin_define
define|#
directive|define
name|AUP_HEX
value|3
end_define

begin_define
define|#
directive|define
name|AUP_STRING
value|4
end_define

begin_comment
comment|/* data-types for the arbitrary token */
end_comment

begin_define
define|#
directive|define
name|AUR_BYTE
value|0
end_define

begin_define
define|#
directive|define
name|AUR_CHAR
value|AUR_BYTE
end_define

begin_define
define|#
directive|define
name|AUR_SHORT
value|1
end_define

begin_define
define|#
directive|define
name|AUR_INT32
value|2
end_define

begin_define
define|#
directive|define
name|AUR_INT
value|AUR_INT32
end_define

begin_define
define|#
directive|define
name|AUR_INT64
value|3
end_define

begin_comment
comment|/* ... and their sizes */
end_comment

begin_define
define|#
directive|define
name|AUR_BYTE_SIZE
value|sizeof(u_char)
end_define

begin_define
define|#
directive|define
name|AUR_CHAR_SIZE
value|AUR_BYTE_SIZE
end_define

begin_define
define|#
directive|define
name|AUR_SHORT_SIZE
value|sizeof(uint16_t)
end_define

begin_define
define|#
directive|define
name|AUR_INT32_SIZE
value|sizeof(uint32_t)
end_define

begin_define
define|#
directive|define
name|AUR_INT_SIZE
value|AUR_INT32_SIZE
end_define

begin_define
define|#
directive|define
name|AUR_INT64_SIZE
value|sizeof(uint64_t)
end_define

begin_comment
comment|/* Modifiers for the header token */
end_comment

begin_define
define|#
directive|define
name|PAD_NOTATTR
value|0x4000
end_define

begin_comment
comment|/* nonattributable event */
end_comment

begin_define
define|#
directive|define
name|PAD_FAILURE
value|0x8000
end_define

begin_comment
comment|/* fail audit event */
end_comment

begin_define
define|#
directive|define
name|AUDIT_MAX_GROUPS
value|16
end_define

begin_comment
comment|/*  * A number of BSM versions are floating around and defined.  Here are  * constants for them.  OpenBSM uses the same token types, etc, used in the  * Solaris BSM version, but has a separate version number in order to  * identify a potentially different event identifier name space.  */
end_comment

begin_define
define|#
directive|define
name|AUDIT_HEADER_VERSION_OLDDARWIN
value|1
end_define

begin_comment
comment|/* In retrospect, a mistake. */
end_comment

begin_define
define|#
directive|define
name|AUDIT_HEADER_VERSION_SOLARIS
value|2
end_define

begin_define
define|#
directive|define
name|AUDIT_HEADER_VERSION_TSOL25
value|3
end_define

begin_define
define|#
directive|define
name|AUDIT_HEADER_VERSION_TSOL
value|4
end_define

begin_define
define|#
directive|define
name|AUDIT_HEADER_VERSION_OPENBSM
value|10
end_define

begin_comment
comment|/*  * BSM define is AUT_TRAILER_MAGIC; Apple BSM define is TRAILER_PAD_MAGIC; we  * split the difference, will remove the Apple define for the next release.  */
end_comment

begin_define
define|#
directive|define
name|AUT_TRAILER_MAGIC
value|0xb105
end_define

begin_define
define|#
directive|define
name|TRAILER_PAD_MAGIC
value|AUT_TRAILER_MAGIC
end_define

begin_comment
comment|/* BSM library calls */
end_comment

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|in_addr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|in6_addr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ip
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ipc_perm
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|kevent
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_in
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_in6
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr_un
struct_decl|;
end_struct_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_struct_decl
struct_decl|struct
name|vnode_au_info
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|au_open
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|au_write
parameter_list|(
name|int
name|d
parameter_list|,
name|token_t
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|au_close
parameter_list|(
name|int
name|d
parameter_list|,
name|int
name|keep
parameter_list|,
name|short
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|au_close_buffer
parameter_list|(
name|int
name|d
parameter_list|,
name|short
name|event
parameter_list|,
name|u_char
modifier|*
name|buffer
parameter_list|,
name|size_t
modifier|*
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|au_close_token
parameter_list|(
name|token_t
modifier|*
name|tok
parameter_list|,
name|u_char
modifier|*
name|buffer
parameter_list|,
name|size_t
modifier|*
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_file
parameter_list|(
name|char
modifier|*
name|file
parameter_list|,
name|struct
name|timeval
name|tm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_header32_tm
parameter_list|(
name|int
name|rec_size
parameter_list|,
name|au_event_t
name|e_type
parameter_list|,
name|au_emod_t
name|e_mod
parameter_list|,
name|struct
name|timeval
name|tm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_header64_tm
parameter_list|(
name|int
name|rec_size
parameter_list|,
name|au_event_t
name|e_type
parameter_list|,
name|au_emod_t
name|e_mod
parameter_list|,
name|struct
name|timeval
name|tm
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_function_decl
name|token_t
modifier|*
name|au_to_header
parameter_list|(
name|int
name|rec_size
parameter_list|,
name|au_event_t
name|e_type
parameter_list|,
name|au_emod_t
name|e_mod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_header32
parameter_list|(
name|int
name|rec_size
parameter_list|,
name|au_event_t
name|e_type
parameter_list|,
name|au_emod_t
name|e_mod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_header64
parameter_list|(
name|int
name|rec_size
parameter_list|,
name|au_event_t
name|e_type
parameter_list|,
name|au_emod_t
name|e_mod
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|token_t
modifier|*
name|au_to_me
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_arg
parameter_list|(
name|char
name|n
parameter_list|,
name|char
modifier|*
name|text
parameter_list|,
name|uint32_t
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_arg32
parameter_list|(
name|char
name|n
parameter_list|,
name|char
modifier|*
name|text
parameter_list|,
name|uint32_t
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_arg64
parameter_list|(
name|char
name|n
parameter_list|,
name|char
modifier|*
name|text
parameter_list|,
name|uint64_t
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_function_decl
name|token_t
modifier|*
name|au_to_attr
parameter_list|(
name|struct
name|vnode_au_info
modifier|*
name|vni
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_attr32
parameter_list|(
name|struct
name|vnode_au_info
modifier|*
name|vni
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_attr64
parameter_list|(
name|struct
name|vnode_au_info
modifier|*
name|vni
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|token_t
modifier|*
name|au_to_data
parameter_list|(
name|char
name|unit_print
parameter_list|,
name|char
name|unit_type
parameter_list|,
name|char
name|unit_count
parameter_list|,
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_exit
parameter_list|(
name|int
name|retval
parameter_list|,
name|int
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_groups
parameter_list|(
name|int
modifier|*
name|groups
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_newgroups
parameter_list|(
name|uint16_t
name|n
parameter_list|,
name|gid_t
modifier|*
name|groups
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_in_addr
parameter_list|(
name|struct
name|in_addr
modifier|*
name|internet_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_in_addr_ex
parameter_list|(
name|struct
name|in6_addr
modifier|*
name|internet_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_ip
parameter_list|(
name|struct
name|ip
modifier|*
name|ip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_ipc
parameter_list|(
name|char
name|type
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_ipc_perm
parameter_list|(
name|struct
name|ipc_perm
modifier|*
name|perm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_iport
parameter_list|(
name|uint16_t
name|iport
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_opaque
parameter_list|(
name|char
modifier|*
name|data
parameter_list|,
name|uint16_t
name|bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_path
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_process
parameter_list|(
name|au_id_t
name|auid
parameter_list|,
name|uid_t
name|euid
parameter_list|,
name|gid_t
name|egid
parameter_list|,
name|uid_t
name|ruid
parameter_list|,
name|gid_t
name|rgid
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|au_asid_t
name|sid
parameter_list|,
name|au_tid_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_process32
parameter_list|(
name|au_id_t
name|auid
parameter_list|,
name|uid_t
name|euid
parameter_list|,
name|gid_t
name|egid
parameter_list|,
name|uid_t
name|ruid
parameter_list|,
name|gid_t
name|rgid
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|au_asid_t
name|sid
parameter_list|,
name|au_tid_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_process64
parameter_list|(
name|au_id_t
name|auid
parameter_list|,
name|uid_t
name|euid
parameter_list|,
name|gid_t
name|egid
parameter_list|,
name|uid_t
name|ruid
parameter_list|,
name|gid_t
name|rgid
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|au_asid_t
name|sid
parameter_list|,
name|au_tid_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_process_ex
parameter_list|(
name|au_id_t
name|auid
parameter_list|,
name|uid_t
name|euid
parameter_list|,
name|gid_t
name|egid
parameter_list|,
name|uid_t
name|ruid
parameter_list|,
name|gid_t
name|rgid
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|au_asid_t
name|sid
parameter_list|,
name|au_tid_addr_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_process32_ex
parameter_list|(
name|au_id_t
name|auid
parameter_list|,
name|uid_t
name|euid
parameter_list|,
name|gid_t
name|egid
parameter_list|,
name|uid_t
name|ruid
parameter_list|,
name|gid_t
name|rgid
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|au_asid_t
name|sid
parameter_list|,
name|au_tid_addr_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_process64_ex
parameter_list|(
name|au_id_t
name|auid
parameter_list|,
name|uid_t
name|euid
parameter_list|,
name|gid_t
name|egid
parameter_list|,
name|uid_t
name|ruid
parameter_list|,
name|gid_t
name|rgid
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|au_asid_t
name|sid
parameter_list|,
name|au_tid_addr_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_return
parameter_list|(
name|char
name|status
parameter_list|,
name|uint32_t
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_return32
parameter_list|(
name|char
name|status
parameter_list|,
name|uint32_t
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_return64
parameter_list|(
name|char
name|status
parameter_list|,
name|uint64_t
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_seq
parameter_list|(
name|long
name|audit_count
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_function_decl
name|token_t
modifier|*
name|au_to_socket
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_socket_ex_32
parameter_list|(
name|uint16_t
name|lp
parameter_list|,
name|uint16_t
name|rp
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|la
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|ta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_socket_ex_128
parameter_list|(
name|uint16_t
name|lp
parameter_list|,
name|uint16_t
name|rp
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|la
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|ta
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|token_t
modifier|*
name|au_to_sock_inet
parameter_list|(
name|struct
name|sockaddr_in
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_sock_inet32
parameter_list|(
name|struct
name|sockaddr_in
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_sock_inet128
parameter_list|(
name|struct
name|sockaddr_in6
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_sock_unix
parameter_list|(
name|struct
name|sockaddr_un
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_subject
parameter_list|(
name|au_id_t
name|auid
parameter_list|,
name|uid_t
name|euid
parameter_list|,
name|gid_t
name|egid
parameter_list|,
name|uid_t
name|ruid
parameter_list|,
name|gid_t
name|rgid
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|au_asid_t
name|sid
parameter_list|,
name|au_tid_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_subject32
parameter_list|(
name|au_id_t
name|auid
parameter_list|,
name|uid_t
name|euid
parameter_list|,
name|gid_t
name|egid
parameter_list|,
name|uid_t
name|ruid
parameter_list|,
name|gid_t
name|rgid
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|au_asid_t
name|sid
parameter_list|,
name|au_tid_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_subject64
parameter_list|(
name|au_id_t
name|auid
parameter_list|,
name|uid_t
name|euid
parameter_list|,
name|gid_t
name|egid
parameter_list|,
name|uid_t
name|ruid
parameter_list|,
name|gid_t
name|rgid
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|au_asid_t
name|sid
parameter_list|,
name|au_tid_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_subject_ex
parameter_list|(
name|au_id_t
name|auid
parameter_list|,
name|uid_t
name|euid
parameter_list|,
name|gid_t
name|egid
parameter_list|,
name|uid_t
name|ruid
parameter_list|,
name|gid_t
name|rgid
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|au_asid_t
name|sid
parameter_list|,
name|au_tid_addr_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_subject32_ex
parameter_list|(
name|au_id_t
name|auid
parameter_list|,
name|uid_t
name|euid
parameter_list|,
name|gid_t
name|egid
parameter_list|,
name|uid_t
name|ruid
parameter_list|,
name|gid_t
name|rgid
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|au_asid_t
name|sid
parameter_list|,
name|au_tid_addr_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_subject64_ex
parameter_list|(
name|au_id_t
name|auid
parameter_list|,
name|uid_t
name|euid
parameter_list|,
name|gid_t
name|egid
parameter_list|,
name|uid_t
name|ruid
parameter_list|,
name|gid_t
name|rgid
parameter_list|,
name|pid_t
name|pid
parameter_list|,
name|au_asid_t
name|sid
parameter_list|,
name|au_tid_addr_t
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_function_decl
name|token_t
modifier|*
name|au_to_exec_args
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|int
name|argc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_exec_env
parameter_list|(
name|char
modifier|*
name|envs
parameter_list|,
name|int
name|envc
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|token_t
modifier|*
name|au_to_exec_args
parameter_list|(
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_exec_env
parameter_list|(
name|char
modifier|*
modifier|*
name|envp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|token_t
modifier|*
name|au_to_text
parameter_list|(
name|char
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_kevent
parameter_list|(
name|struct
name|kevent
modifier|*
name|kev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_trailer
parameter_list|(
name|int
name|rec_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|token_t
modifier|*
name|au_to_zonename
parameter_list|(
name|char
modifier|*
name|zonename
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _BSM_AUDIT_RECORD_H_ */
end_comment

end_unit

