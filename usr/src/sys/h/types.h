begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)types.h	7.3 (Berkeley) 6/20/87  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TYPES_
end_ifndef

begin_define
define|#
directive|define
name|_TYPES_
end_define

begin_comment
comment|/*  * Basic system types and major/minor device constructing/busting macros.  */
end_comment

begin_comment
comment|/* major part of a device */
end_comment

begin_define
define|#
directive|define
name|major
parameter_list|(
name|x
parameter_list|)
value|((int)(((unsigned)(x)>>8)&0377))
end_define

begin_comment
comment|/* minor part of a device */
end_comment

begin_define
define|#
directive|define
name|minor
parameter_list|(
name|x
parameter_list|)
value|((int)((x)&0377))
end_define

begin_comment
comment|/* make a device number */
end_comment

begin_define
define|#
directive|define
name|makedev
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((dev_t)(((x)<<8) | (y)))
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u_char
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u_short
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u_long
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ushort
typedef|;
end_typedef

begin_comment
comment|/* sys III compat */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_typedef
typedef|typedef
struct|struct
name|_physadr
block|{
name|int
name|r
index|[
literal|1
index|]
decl_stmt|;
block|}
typedef|*
name|physadr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|label_t
block|{
name|int
name|val
index|[
literal|14
index|]
decl_stmt|;
block|}
name|label_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_quad
block|{
name|long
name|val
index|[
literal|2
index|]
decl_stmt|;
block|}
name|quad
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|daddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|caddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
modifier|*
name|qaddr_t
typedef|;
end_typedef

begin_comment
comment|/* should be typedef quad * qaddr_t; */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|swblk_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|off_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|gid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NBBY
value|8
end_define

begin_comment
comment|/* number of bits in a byte */
end_comment

begin_comment
comment|/*  * Select uses bit masks of file descriptors in longs.  * These macros manipulate such bit fields (the filesystem macros use chars).  * FD_SETSIZE may be defined by the user, but the default here  * should be>= NOFILE (param.h).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FD_SETSIZE
end_ifndef

begin_define
define|#
directive|define
name|FD_SETSIZE
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|long
name|fd_mask
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NFDBITS
value|(sizeof(fd_mask) * NBBY)
end_define

begin_comment
comment|/* bits per mask */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|howmany
end_ifndef

begin_define
define|#
directive|define
name|howmany
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)+((y)-1))/(y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|fd_set
block|{
name|fd_mask
name|fds_bits
index|[
name|howmany
argument_list|(
name|FD_SETSIZE
argument_list|,
name|NFDBITS
argument_list|)
index|]
decl_stmt|;
block|}
name|fd_set
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS] |= (1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_CLR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS]&= ~(1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS]& (1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|p
parameter_list|)
value|bzero((char *)(p), sizeof(*(p)))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

