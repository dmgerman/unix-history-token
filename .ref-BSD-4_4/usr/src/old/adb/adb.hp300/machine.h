begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	machine.h	4.1	81/05/14	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEWVM
end_ifdef

begin_include
include|#
directive|include
file|<machine/param.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/vm.h>
end_include

begin_include
include|#
directive|include
file|<machine/machparam.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/vmparam.h>
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
value|"%X"
end_define

begin_define
define|#
directive|define
name|OFFMODE
value|"+%X"
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
value|USRSTACK
end_define

begin_define
define|#
directive|define
name|MAXFILE
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|LOWRAM
value|0xfffffdce
end_define

begin_comment
comment|/*  * INSTACK tells whether its argument is a stack address.  * INUDOT tells whether its argument is in the (extended) u. area.  * These are used for consistency checking and don't have to be exact.  *  * INKERNEL tells whether its argument is a kernel space address.  * KVTOPH trims a kernel virtal address back to its offset  * in the kernel address space.  */
end_comment

begin_define
define|#
directive|define
name|INSTACK
parameter_list|(
name|x
parameter_list|)
value|(((x)&0xf0000000) == 0xf0000000)
end_define

begin_define
define|#
directive|define
name|INUDOT
parameter_list|(
name|x
parameter_list|)
value|((x)>= kernudot&& (x)< kernudot + ctob(UPAGES))
end_define

begin_define
define|#
directive|define
name|INKERNEL
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)> KERNOFF&& (x)< KERNOFF + ctob(slr))
end_define

begin_define
define|#
directive|define
name|KVTOPH
parameter_list|(
name|x
parameter_list|)
value|(((x) - KERNOFF) + (kmem ? lowram : 0))
end_define

begin_define
define|#
directive|define
name|KERNOFF
value|(unsigned)KERNBASE
end_define

begin_decl_stmt
name|unsigned
name|lowram
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kernudot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kmem
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|mc68010
value|1
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|mc68020
value|1
end_define

begin_comment
comment|/* XXX */
end_comment

end_unit

