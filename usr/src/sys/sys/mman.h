begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)mman.h	7.8 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Protections are chosen from these bits, or-ed together  */
end_comment

begin_define
define|#
directive|define
name|PROT_READ
value|0x01
end_define

begin_comment
comment|/* pages can be read */
end_comment

begin_define
define|#
directive|define
name|PROT_WRITE
value|0x02
end_define

begin_comment
comment|/* pages can be written */
end_comment

begin_define
define|#
directive|define
name|PROT_EXEC
value|0x04
end_define

begin_comment
comment|/* pages can be executed */
end_comment

begin_comment
comment|/*  * Flags contain sharing type and options.  * Sharing types; choose one.  */
end_comment

begin_define
define|#
directive|define
name|MAP_SHARED
value|0x0001
end_define

begin_comment
comment|/* share changes */
end_comment

begin_define
define|#
directive|define
name|MAP_PRIVATE
value|0x0002
end_define

begin_comment
comment|/* changes are private */
end_comment

begin_define
define|#
directive|define
name|MAP_COPY
value|0x0004
end_define

begin_comment
comment|/* "copy" region at mmap time */
end_comment

begin_comment
comment|/*  * Other flags  */
end_comment

begin_define
define|#
directive|define
name|MAP_FIXED
value|0x0010
end_define

begin_comment
comment|/* map addr must be exactly as requested */
end_comment

begin_define
define|#
directive|define
name|MAP_RENAME
value|0x0020
end_define

begin_comment
comment|/* Sun: rename private pages to file */
end_comment

begin_define
define|#
directive|define
name|MAP_NORESERVE
value|0x0040
end_define

begin_comment
comment|/* Sun: don't reserve needed swap area */
end_comment

begin_define
define|#
directive|define
name|MAP_INHERIT
value|0x0080
end_define

begin_comment
comment|/* region is retained after exec */
end_comment

begin_define
define|#
directive|define
name|MAP_NOEXTEND
value|0x0100
end_define

begin_comment
comment|/* for MAP_FILE, don't change file size */
end_comment

begin_define
define|#
directive|define
name|MAP_HASSEMAPHORE
value|0x0200
end_define

begin_comment
comment|/* region may contain semaphores */
end_comment

begin_comment
comment|/*  * Mapping type; default is map from file.  */
end_comment

begin_define
define|#
directive|define
name|MAP_ANON
value|0x1000
end_define

begin_comment
comment|/* allocated from memory, swap space */
end_comment

begin_comment
comment|/*  * Advice to madvise  */
end_comment

begin_define
define|#
directive|define
name|MADV_NORMAL
value|0
end_define

begin_comment
comment|/* no further special treatment */
end_comment

begin_define
define|#
directive|define
name|MADV_RANDOM
value|1
end_define

begin_comment
comment|/* expect random page references */
end_comment

begin_define
define|#
directive|define
name|MADV_SEQUENTIAL
value|2
end_define

begin_comment
comment|/* expect sequential page references */
end_comment

begin_define
define|#
directive|define
name|MADV_WILLNEED
value|3
end_define

begin_comment
comment|/* will need these pages */
end_comment

begin_define
define|#
directive|define
name|MADV_DONTNEED
value|4
end_define

begin_comment
comment|/* dont need these pages */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
comment|/* Some of these int's should probably be size_t's */
name|caddr_t
name|mmap
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|size_t
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|off_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mprotect
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|size_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|munmap
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|msync
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mlock
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|munlock
name|__P
argument_list|(
operator|(
name|caddr_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KERNEL */
end_comment

end_unit

