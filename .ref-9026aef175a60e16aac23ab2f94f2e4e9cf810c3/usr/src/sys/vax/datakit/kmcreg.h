begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)kmc.h	1.1	*/
end_comment

begin_define
define|#
directive|define
name|KSTEP
value|1
end_define

begin_define
define|#
directive|define
name|KMS
value|2
end_define

begin_define
define|#
directive|define
name|KCSR
value|3
end_define

begin_define
define|#
directive|define
name|KSTOP
value|4
end_define

begin_define
define|#
directive|define
name|KMCLR
value|5
end_define

begin_define
define|#
directive|define
name|KRUN
value|6
end_define

begin_define
define|#
directive|define
name|KLU
value|7
end_define

begin_define
define|#
directive|define
name|KWRCR
value|8
end_define

begin_define
define|#
directive|define
name|KRESET
value|9
end_define

begin_struct
struct|struct
name|kmcntl
block|{
name|int
name|kmd
decl_stmt|;
name|short
modifier|*
name|kcsr
decl_stmt|;
name|int
name|kval
decl_stmt|;
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_define
define|#
directive|define
name|KCSETA
value|_IOW('k', 1, struct kmcntl)
end_define

begin_define
define|#
directive|define
name|lobyte
parameter_list|(
name|X
parameter_list|)
value|(((unsigned char *)&X)[0])
end_define

begin_define
define|#
directive|define
name|hibyte
parameter_list|(
name|X
parameter_list|)
value|(((unsigned char *)&X)[1])
end_define

begin_define
define|#
directive|define
name|loword
parameter_list|(
name|X
parameter_list|)
value|(((ushort *)&X)[0])
end_define

begin_define
define|#
directive|define
name|hiword
parameter_list|(
name|X
parameter_list|)
value|(((ushort *)&X)[1])
end_define

end_unit

