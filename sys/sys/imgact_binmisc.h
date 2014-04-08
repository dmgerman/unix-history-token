begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Stacey D. Son  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IMGACT_BINMISC_H_
end_ifndef

begin_define
define|#
directive|define
name|_IMGACT_BINMISC_H_
end_define

begin_comment
comment|/**  * Miscellaneous binary interpreter image activator.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* for MAXPATHLEN */
end_comment

begin_comment
comment|/*  * Imgact bin misc parameters.  */
end_comment

begin_define
define|#
directive|define
name|IBE_VERSION
value|1
end_define

begin_comment
comment|/* struct ximgact_binmisc_entry version. */
end_comment

begin_define
define|#
directive|define
name|IBE_NAME_MAX
value|32
end_define

begin_comment
comment|/* Max size for entry name. */
end_comment

begin_define
define|#
directive|define
name|IBE_MAGIC_MAX
value|256
end_define

begin_comment
comment|/* Max size for header magic and mask. */
end_comment

begin_define
define|#
directive|define
name|IBE_ARG_LEN_MAX
value|256
end_define

begin_comment
comment|/* Max space for optional interpreter command- 				   line argruments seperated by white space */
end_comment

begin_define
define|#
directive|define
name|IBE_INTERP_LEN_MAX
value|(MAXPATHLEN + IBE_ARG_LEN_MAX)
end_define

begin_define
define|#
directive|define
name|IBE_MAX_ENTRIES
value|64
end_define

begin_comment
comment|/* Max number of interpreter entries. */
end_comment

begin_comment
comment|/*  * Imgact bin misc interpreter entry flags.  */
end_comment

begin_define
define|#
directive|define
name|IBF_ENABLED
value|0x0001
end_define

begin_comment
comment|/* Entry is active. */
end_comment

begin_define
define|#
directive|define
name|IBF_USE_MASK
value|0x0002
end_define

begin_comment
comment|/* Use mask on header magic field. */
end_comment

begin_comment
comment|/*  * Used with sysctlbyname() to pass imgact bin misc entries in and out of the  * kernel.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ximgact_binmisc_entry
block|{
name|uint32_t
name|xbe_version
decl_stmt|;
comment|/* Struct version(IBE_VERSION) */
name|uint32_t
name|xbe_flags
decl_stmt|;
comment|/* Entry flags (IBF_*) */
name|uint32_t
name|xbe_moffset
decl_stmt|;
comment|/* Magic offset in header */
name|uint32_t
name|xbe_msize
decl_stmt|;
comment|/* Magic size */
name|uint32_t
name|spare
index|[
literal|3
index|]
decl_stmt|;
comment|/* Spare fields for future use */
name|char
name|xbe_name
index|[
name|IBE_NAME_MAX
index|]
decl_stmt|;
comment|/* Unique interpreter name */
name|char
name|xbe_interpreter
index|[
name|IBE_INTERP_LEN_MAX
index|]
decl_stmt|;
comment|/* Interpreter path + args */
name|uint8_t
name|xbe_magic
index|[
name|IBE_MAGIC_MAX
index|]
decl_stmt|;
comment|/* Header Magic */
name|uint8_t
name|xbe_mask
index|[
name|IBE_MAGIC_MAX
index|]
decl_stmt|;
comment|/* Magic Mask */
block|}
name|ximgact_binmisc_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * sysctl() command names.  */
end_comment

begin_define
define|#
directive|define
name|IBE_SYSCTL_NAME
value|"kern.binmisc"
end_define

begin_define
define|#
directive|define
name|IBE_SYSCTL_NAME_ADD
value|IBE_SYSCTL_NAME ".add"
end_define

begin_define
define|#
directive|define
name|IBE_SYSCTL_NAME_REMOVE
value|IBE_SYSCTL_NAME ".remove"
end_define

begin_define
define|#
directive|define
name|IBE_SYSCTL_NAME_DISABLE
value|IBE_SYSCTL_NAME ".disable"
end_define

begin_define
define|#
directive|define
name|IBE_SYSCTL_NAME_ENABLE
value|IBE_SYSCTL_NAME ".enable"
end_define

begin_define
define|#
directive|define
name|IBE_SYSCTL_NAME_LOOKUP
value|IBE_SYSCTL_NAME ".lookup"
end_define

begin_define
define|#
directive|define
name|IBE_SYSCTL_NAME_LIST
value|IBE_SYSCTL_NAME ".list"
end_define

begin_define
define|#
directive|define
name|KMOD_NAME
value|"imgact_binmisc"
end_define

begin_comment
comment|/*  * Examples of manipulating he interpreter table using sysctlbyname(3):  *  * #include<sys/imgact_binmisc.h>  *  * #define LLVM_MAGIC  "BC\xc0\xde"  *  * #define MIPS64_ELF_MAGIC	"\x7f\x45\x4c\x46\x02\x02\x01\x00\x00\x00" \  *				"\x00\x00\x00\x00\x00\x00\x00\x02\x00\x08"  * #define MIPS64_ELF_MASK	"\xff\xff\xff\xff\xff\xff\xff\x00\xff\xff" \  *				"\xff\xff\xff\xff\xff\xff\xff\xfe\xff\xff"  *  * ximgact_binmisc_entry_t xbe, *xbep, out_xbe;  * size_t size = 0, osize;  * int error, i;  *  * // Add image activator for LLVM byte code  * bzero(&xbe, sizeof(xbe));  * xbe.xbe_version = IBE_VERSION;  * xbe.xbe_flags = IBF_ENABLED;  * strlcpy(xbe.xbe_name, "llvm_bc", IBE_NAME_MAX);  * strlcpy(xbe.xbe_interpreter, "/usr/bin/lli --fake-arg0=#a",  *     IBE_INTERP_LEN_MAX);  * xbe.xbe_moffset = 0;  * xbe.xbe_msize = 4;  * memcpy(xbe.xbe_magic, LLVM_MAGIC, xbe.xbe_msize);  * error = sysctlbyname(IBE_SYSCTL_NAME_ADD, NULL, NULL,&xbe, sizeof(xbe));  *  * // Add image activator for mips64 ELF binaries to use qemu user mode  * bzero(&xbe, sizeof(xbe));  * xbe.xbe_version = IBE_VERSION;  * xbe.xbe_flags = IBF_ENABLED | IBF_USE_MASK;  * strlcpy(xbe.xbe_name, "mips64elf", IBE_NAME_MAX);  * strlcpy(xbe.xbe_interpreter, "/usr/local/bin/qemu-mips64",  *	IBE_INTERP_LEN_MAX);  * xbe.xbe_moffset = 0;  * xbe.xbe_msize = 20;  * memcpy(xbe.xbe_magic, MIPS64_ELF_MAGIC, xbe.xbe_msize);  * memcpy(xbe.xbe_mask, MIPS64_ELF_MASK, xbe.xbe_msize);  * sysctlbyname(IBE_SYSCTL_NAME_ADD, NULL, NULL,&xbe, sizeof(xbe));  *  * // Disable (OR Enable OR Remove) image activator for LLVM byte code  * bzero(&xbe, sizeof(xbe));  * xbe.xbe_version = IBE_VERSION;  * strlcpy(xbe.xbe_name, "llvm_bc", IBE_NAME_MAX);  * error = sysctlbyname(IBE_SYSCTL_NAME_DISABLE, NULL, NULL,&xbe, sizeof(xbe));  * // OR sysctlbyname(IBE_SYSCTL_NAME_ENABLE", NULL, NULL,&xbe, sizeof(xbe));  * // OR sysctlbyname(IBE_SYSCTL_NAME_REMOVE, NULL, NULL,&xbe, sizeof(xbe));  *  * // Lookup image activator  "llvm_bc"  * bzero(&xbe, sizeof(xbe));  * xbe.xbe_version = IBE_VERSION;  * strlcpy(xbe.xbe_name, "llvm_bc", IBE_NAME_MAX);  * size = sizeof(out_xbe);  * error = sysctlbyname(IBE_SYSCTL_NAME_LOOKUP,&out_xbe,&size,&xbe,  *	sizeof(xbe));  *  * // Get all the currently configured image activators and report  * error = sysctlbyname(IBE_SYSCTL_NAME_LIST, NULL,&size, NULL, 0);  * if (0 == error&& size> 0) {  *	xbep = malloc(size);  *	while(1) {  *	    osize = size;  *	    error = sysctlbyname("kern.binmisc.list", xbep,&size, NULL, 0);  *	    if (-1 == error&& ENOMEM == errno&& size == osize) {  *		// The buffer too small and needs to grow  *		size += sizeof(xbe);  *		xbep = realloc(xbep, size);  *	    } else  *		break;  *	}  * }  * for(i = 0; i< (size / sizeof(xbe)); i++, xbep++)  *	printf("name: %s interpreter: %s flags: %s %s\n", xbep->xbe_name,  *	    xbep->xbe_interpreter, (xbep->xbe_flags& IBF_ENABLED) ?  *	    "ENABLED" : "", (xbep->xbe_flags& IBF_ENABLED) ? "USE_MASK" : "");  *  * The sysctlbyname() calls above may return the following errors in addition  * to the standard ones:  *  * [EINVAL]  Invalid argument in the input ximgact_binmisc_entry_t structure.  * [EEXIST]  Interpreter entry for given name already exist in kernel list.  * [ENOMEM]  Allocating memory in the kernel failed or, in the case of  *           kern.binmisc.list, the user buffer is too small.  * [ENOENT]  Interpreter entry for given name is not found.  * [ENOSPC]  Attempted to exceed maximum number of entries (IBE_MAX_ENTRIES).  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IMGACT_BINMISC_H_ */
end_comment

end_unit

