begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gpib data structures */
end_comment

begin_struct
struct|struct
name|gpibdata
block|{
name|char
modifier|*
name|data
decl_stmt|;
comment|/* data string for ins and outs	*/
name|unsigned
name|char
name|address
decl_stmt|;
comment|/* gpib address */
name|int
modifier|*
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* IOCTL commands */
end_comment

begin_define
define|#
directive|define
name|GPIBWRITE
value|_IOW('g',1,struct gpibdata)
end_define

begin_define
define|#
directive|define
name|GPIBREAD
value|_IOW('g',2,struct gpibdata)
end_define

begin_define
define|#
directive|define
name|GPIBINIT
value|_IOW('g',3,struct gpibdata)
end_define

begin_define
define|#
directive|define
name|GPIBTRIGGER
value|_IOW('g',4,struct gpibdata)
end_define

begin_define
define|#
directive|define
name|GPIBREMOTE
value|_IOW('g',5,struct gpibdata)
end_define

begin_define
define|#
directive|define
name|GPIBLOCAL
value|_IOW('g',6,struct gpibdata)
end_define

begin_define
define|#
directive|define
name|GPIBMTRIGGER
value|_IOW('g',7,struct gpibdata)
end_define

begin_define
define|#
directive|define
name|GPIBMREMOTE
value|_IOW('g',8,struct gpibdata)
end_define

begin_define
define|#
directive|define
name|GPIBMLOCAL
value|_IOW('g',9,struct gpibdata)
end_define

begin_define
define|#
directive|define
name|GPIBSPOLL
value|_IOW('g',10,struct gpibdata)
end_define

end_unit

