begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
name|long
name|daddr_t
typedef|;
end_typedef

begin_comment
comment|/* disk address */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|caddr_t
typedef|;
end_typedef

begin_comment
comment|/* core address */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ino_t
typedef|;
end_typedef

begin_comment
comment|/* i-node number */
end_comment

begin_typedef
typedef|typedef
name|long
name|time_t
typedef|;
end_typedef

begin_comment
comment|/* a time */
end_comment

begin_typedef
typedef|typedef
name|int
name|label_t
index|[
literal|6
index|]
typedef|;
end_typedef

begin_comment
comment|/* program status */
end_comment

begin_typedef
typedef|typedef
name|int
name|dev_t
typedef|;
end_typedef

begin_comment
comment|/* device code */
end_comment

begin_typedef
typedef|typedef
name|long
name|off_t
typedef|;
end_typedef

begin_comment
comment|/* offset in file */
end_comment

begin_comment
comment|/* selectors and constructor for device code */
end_comment

begin_define
define|#
directive|define
name|major
parameter_list|(
name|x
parameter_list|)
value|(int)(((unsigned)x>>8))
end_define

begin_define
define|#
directive|define
name|minor
parameter_list|(
name|x
parameter_list|)
value|(int)(x&0377)
end_define

begin_define
define|#
directive|define
name|makedev
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(dev_t)((x)<<8|(y))
end_define

end_unit

