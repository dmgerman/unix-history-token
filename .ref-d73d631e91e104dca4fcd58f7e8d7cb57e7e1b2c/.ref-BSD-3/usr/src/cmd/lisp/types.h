begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|rrr
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
name|unsigned
name|short
name|ino_t
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
name|int
name|label_t
index|[
literal|10
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
name|long
name|off_t
typedef|;
end_typedef

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
value|(int)(((unsigned)x>>8)&0377)
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
value|(int)(x&0377)
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
value|(dev_t)(((x)<<8) | (y))
end_define

end_unit

