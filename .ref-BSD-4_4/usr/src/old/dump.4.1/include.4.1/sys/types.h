begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	types.h	4.3	81/10/17	*/
end_comment

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

begin_comment
comment|/* SHOULD USE long RATHER THAN int HERE BUT IT WOULD GIVE LINT ON THE KERNEL */
end_comment

begin_comment
comment|/* GASTRIC DISTRESS AND DON'T HAVE TIME TO FIX THAT JUST NOW */
end_comment

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
name|int
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
name|u_short
name|ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|swblk_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|label_t
index|[
literal|14
index|]
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
name|int
name|off_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|portid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|fd_set
block|{
name|int
name|fds_bits
index|[
literal|1
index|]
decl_stmt|;
block|}
name|fd_set
typedef|;
end_typedef

end_unit

