begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	machine.h	1.1	86/02/25	*/
end_comment

begin_include
include|#
directive|include
file|<sys/vm.h>
end_include

begin_define
define|#
directive|define
name|PAGSIZ
value|(NBPG*CLSIZE)
end_define

begin_define
define|#
directive|define
name|DBNAME
value|"adb\n"
end_define

begin_define
define|#
directive|define
name|LPRMODE
value|"%R"
end_define

begin_define
define|#
directive|define
name|OFFMODE
value|"+%R"
end_define

begin_define
define|#
directive|define
name|TXTRNDSIZ
value|PAGSIZ
end_define

begin_define
define|#
directive|define
name|MAXINT
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|MAXSTOR
value|(KERNBASE - ctob(UPAGES))
end_define

begin_define
define|#
directive|define
name|MAXFILE
value|0xffffffff
end_define

begin_comment
comment|/*  * INSTACK tells whether its argument is a stack address.  * INUDOT tells whether its argument is in the (extended) u. area.  * These are used for consistency checking and dont have to be exact.  *  * INKERNEL tells whether its argument is a kernel space address.  * KVTOPH trims a kernel virtal address back to its offset  * in the kernel address space.  */
end_comment

begin_define
define|#
directive|define
name|INSTACK
parameter_list|(
name|x
parameter_list|)
value|(((int)(x)&0xf0000000) == 0xb0000000)
end_define

begin_define
define|#
directive|define
name|INUDOT
parameter_list|(
name|x
parameter_list|)
value|(((int)(x)&0xf0000000) == 0xb0000000)
end_define

begin_define
define|#
directive|define
name|INKERNEL
parameter_list|(
name|x
parameter_list|)
value|(((int)(x)&0xf0000000) == 0xc0000000)
end_define

begin_define
define|#
directive|define
name|KERNBASE
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|KERNOFF
value|(KERNBASE + 0x800)
end_define

begin_comment
comment|/* start of kernel's text */
end_comment

begin_define
define|#
directive|define
name|KVTOPH
parameter_list|(
name|x
parameter_list|)
value|((x)&~ 0xc0000000)
end_define

end_unit

