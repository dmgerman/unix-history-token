begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sdbm - ndbm work-alike hashed database library  * based on Per-Ake Larson's Dynamic Hashing algorithms. BIT 18 (1978).  * author: oz@nexus.yorku.ca  * status: public domain.   */
end_comment

begin_define
define|#
directive|define
name|DBLKSIZ
value|4096
end_define

begin_define
define|#
directive|define
name|PBLKSIZ
value|1024
end_define

begin_define
define|#
directive|define
name|PAIRMAX
value|1008
end_define

begin_comment
comment|/* arbitrary on PBLKSIZ-N */
end_comment

begin_define
define|#
directive|define
name|SPLTMAX
value|10
end_define

begin_comment
comment|/* maximum allowed splits */
end_comment

begin_comment
comment|/* for a single insertion */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|DIRFEXT
value|".sdbm_dir"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DIRFEXT
value|".dir"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PAGFEXT
value|".pag"
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|dirf
decl_stmt|;
comment|/* directory file descriptor */
name|int
name|pagf
decl_stmt|;
comment|/* page file descriptor */
name|int
name|flags
decl_stmt|;
comment|/* status/error flags, see below */
name|long
name|maxbno
decl_stmt|;
comment|/* size of dirfile in bits */
name|long
name|curbit
decl_stmt|;
comment|/* current bit number */
name|long
name|hmask
decl_stmt|;
comment|/* current hash mask */
name|long
name|blkptr
decl_stmt|;
comment|/* current block for nextkey */
name|int
name|keyptr
decl_stmt|;
comment|/* current key for nextkey */
name|long
name|blkno
decl_stmt|;
comment|/* current page to read/write */
name|long
name|pagbno
decl_stmt|;
comment|/* current page in pagbuf */
name|char
name|pagbuf
index|[
name|PBLKSIZ
index|]
decl_stmt|;
comment|/* page file block buffer */
name|long
name|dirbno
decl_stmt|;
comment|/* current block in dirbuf */
name|char
name|dirbuf
index|[
name|DBLKSIZ
index|]
decl_stmt|;
comment|/* directory file block buffer */
block|}
name|DBM
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DBM_RDONLY
value|0x1
end_define

begin_comment
comment|/* data base open read-only */
end_comment

begin_define
define|#
directive|define
name|DBM_IOERR
value|0x2
end_define

begin_comment
comment|/* data base I/O error */
end_comment

begin_comment
comment|/*  * utility macros  */
end_comment

begin_define
define|#
directive|define
name|sdbm_rdonly
parameter_list|(
name|db
parameter_list|)
value|((db)->flags& DBM_RDONLY)
end_define

begin_define
define|#
directive|define
name|sdbm_error
parameter_list|(
name|db
parameter_list|)
value|((db)->flags& DBM_IOERR)
end_define

begin_define
define|#
directive|define
name|sdbm_clearerr
parameter_list|(
name|db
parameter_list|)
value|((db)->flags&= ~DBM_IOERR)
end_define

begin_comment
comment|/* ouch */
end_comment

begin_define
define|#
directive|define
name|sdbm_dirfno
parameter_list|(
name|db
parameter_list|)
value|((db)->dirf)
end_define

begin_define
define|#
directive|define
name|sdbm_pagfno
parameter_list|(
name|db
parameter_list|)
value|((db)->pagf)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|dptr
decl_stmt|;
name|int
name|dsize
decl_stmt|;
block|}
name|datum
typedef|;
end_typedef

begin_decl_stmt
name|EXTCONST
name|datum
name|nullitem
ifdef|#
directive|ifdef
name|DOINIT
init|=
block|{
literal|0
block|,
literal|0
block|}
endif|#
directive|endif
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|CAN_PROTOTYPE
argument_list|)
end_if

begin_define
define|#
directive|define
name|proto
parameter_list|(
name|p
parameter_list|)
value|p
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|proto
parameter_list|(
name|p
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * flags to sdbm_store  */
end_comment

begin_define
define|#
directive|define
name|DBM_INSERT
value|0
end_define

begin_define
define|#
directive|define
name|DBM_REPLACE
value|1
end_define

begin_comment
comment|/*  * ndbm interface  */
end_comment

begin_decl_stmt
specifier|extern
name|DBM
modifier|*
name|sdbm_open
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sdbm_close
name|proto
argument_list|(
operator|(
name|DBM
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|datum
name|sdbm_fetch
name|proto
argument_list|(
operator|(
name|DBM
operator|*
operator|,
name|datum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sdbm_delete
name|proto
argument_list|(
operator|(
name|DBM
operator|*
operator|,
name|datum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sdbm_store
name|proto
argument_list|(
operator|(
name|DBM
operator|*
operator|,
name|datum
operator|,
name|datum
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|datum
name|sdbm_firstkey
name|proto
argument_list|(
operator|(
name|DBM
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|datum
name|sdbm_nextkey
name|proto
argument_list|(
operator|(
name|DBM
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * other  */
end_comment

begin_decl_stmt
specifier|extern
name|DBM
modifier|*
name|sdbm_prep
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|sdbm_hash
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|SDBM_ONLY
end_ifndef

begin_define
define|#
directive|define
name|dbm_open
value|sdbm_open
end_define

begin_define
define|#
directive|define
name|dbm_close
value|sdbm_close
end_define

begin_define
define|#
directive|define
name|dbm_fetch
value|sdbm_fetch
end_define

begin_define
define|#
directive|define
name|dbm_store
value|sdbm_store
end_define

begin_define
define|#
directive|define
name|dbm_delete
value|sdbm_delete
end_define

begin_define
define|#
directive|define
name|dbm_firstkey
value|sdbm_firstkey
end_define

begin_define
define|#
directive|define
name|dbm_nextkey
value|sdbm_nextkey
end_define

begin_define
define|#
directive|define
name|dbm_error
value|sdbm_error
end_define

begin_define
define|#
directive|define
name|dbm_clearerr
value|sdbm_clearerr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Most of the following is stolen from perl.h. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|H_PERL
end_ifndef

begin_comment
comment|/* Include guard */
end_comment

begin_comment
comment|/*  * The following contortions are brought to you on behalf of all the  * standards, semi-standards, de facto standards, not-so-de-facto standards  * of the world, as well as all the other botches anyone ever thought of.  * The basic theory is that if we work hard enough here, the rest of the  * code can be a lot prettier.  Well, so much for theory.  Sorry, Henry...  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SOCKET
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|I_NET_ERRNO
end_ifdef

begin_include
include|#
directive|include
file|<net/errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|||
name|defined
argument_list|(
name|__stdc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|STANDARD_C
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|I_UNISTD
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_include
include|#
directive|include
file|<file.h>
end_include

begin_include
include|#
directive|include
file|<unixio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_SYS_PARAM
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|PARAM_NEEDS_TYPES
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_TYPES_
end_ifndef

begin_comment
comment|/* If types.h defines this it's easy. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|major
end_ifndef

begin_comment
comment|/* Does everyone's types.h define this? */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|L_SET
end_ifdef

begin_define
define|#
directive|define
name|SEEK_SET
value|L_SET
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_comment
comment|/* Wild guess. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use all the "standard" definitions? */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STANDARD_C
argument_list|)
operator|&&
name|defined
argument_list|(
name|I_STDLIB
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STANDARD_C */
end_comment

begin_define
define|#
directive|define
name|MEM_SIZE
value|Size_t
end_define

begin_comment
comment|/* This comes after<stdlib.h> so we don't try to change the standard  * library prototypes; we'll use our own instead. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MYMALLOC
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|HIDEMYMALLOC
argument_list|)
operator|||
name|defined
argument_list|(
name|EMBEDMYMALLOC
argument_list|)
operator|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|HIDEMYMALLOC
end_ifdef

begin_define
define|#
directive|define
name|malloc
value|Mymalloc
end_define

begin_define
define|#
directive|define
name|calloc
value|Mycalloc
end_define

begin_define
define|#
directive|define
name|realloc
value|Myremalloc
end_define

begin_define
define|#
directive|define
name|free
value|Myfree
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EMBEDMYMALLOC
end_ifdef

begin_define
define|#
directive|define
name|malloc
value|Perl_malloc
end_define

begin_define
define|#
directive|define
name|calloc
value|Perl_calloc
end_define

begin_define
define|#
directive|define
name|realloc
value|Perl_realloc
end_define

begin_define
define|#
directive|define
name|free
value|Perl_free
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|Malloc_t
name|malloc
name|proto
argument_list|(
operator|(
name|MEM_SIZE
name|nbytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Malloc_t
name|calloc
name|proto
argument_list|(
operator|(
name|MEM_SIZE
name|elements
operator|,
name|MEM_SIZE
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Malloc_t
name|realloc
name|proto
argument_list|(
operator|(
name|Malloc_t
name|where
operator|,
name|MEM_SIZE
name|nbytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Free_t
name|free
name|proto
argument_list|(
operator|(
name|Malloc_t
name|where
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MYMALLOC&& (HIDEMYMALLOC || EMBEDMYMALLOC) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I_STRING
end_ifdef

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_MEMORY
end_ifdef

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|HAS_MEMCPY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_MEMCPY
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STANDARD_C
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|I_STRING
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|I_MEMORY
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|memcpy
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|memcpy
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|memcpy
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_BCOPY
end_ifdef

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|bcopy(s,d,l)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|my_bcopy(s,d,l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_MEMCPY */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_MEMSET
end_ifdef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STANDARD_C
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|I_STRING
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|I_MEMORY
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|memset
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|memset
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|d
parameter_list|,
name|l
parameter_list|)
value|memset(d,0,l)
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|memzero
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_BZERO
end_ifdef

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|d
parameter_list|,
name|l
parameter_list|)
value|bzero(d,l)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|d
parameter_list|,
name|l
parameter_list|)
value|my_bzero(d,l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_MEMSET */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|mips
argument_list|)
operator|&&
name|defined
argument_list|(
name|ultrix
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAS_MEMCMP
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAS_MEMCMP
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAS_SANE_MEMCMP
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STANDARD_C
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|I_STRING
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|I_MEMORY
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|memcmp
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|memcmp
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BUGGY_MSC
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|function
name|(
name|memcmp
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|memcmp
end_ifndef

begin_comment
comment|/* maybe we should have included the full embedding header... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_EMBED
end_ifdef

begin_define
define|#
directive|define
name|memcmp
value|my_memcmp
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|memcmp
value|Perl_my_memcmp
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|memcmp
name|proto
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAS_MEMCMP */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_BCMP
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|bcmp
end_ifndef

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|memcmp(s1,s2,l)
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
comment|/* !HAS_BCMP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_MEMCMP
end_ifdef

begin_define
define|#
directive|define
name|memNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(memcmp(s1,s2,l))
end_define

begin_define
define|#
directive|define
name|memEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(!memcmp(s1,s2,l))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|memNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(bcmp(s1,s2,l))
end_define

begin_define
define|#
directive|define
name|memEQ
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|,
name|l
parameter_list|)
value|(!bcmp(s1,s2,l))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_NETINET_IN
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_include
include|#
directive|include
file|<in.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include guard */
end_comment

end_unit

