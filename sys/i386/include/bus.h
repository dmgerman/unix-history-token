begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is in the public domain.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_BUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_BUS_H_
end_define

begin_include
include|#
directive|include
file|<x86/bus.h>
end_include

begin_comment
comment|/*  * The functions:  *    bus_space_read_8  *    bus_space_read_region_8  *    bus_space_write_8  *    bus_space_write_multi_8  *    bus_space_write_region_8  *    bus_space_set_multi_8  *    bus_space_set_region_8  *    bus_space_copy_region_8  *    bus_space_read_multi_8  * are unimplemented for i386 because there is no way to do a 64-bit move in  * this architecture. It is possible to do two 32-bit moves, but this is  * not atomic and may have hardware dependencies that should be fully  * understood.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_MACHINE_BUS_H_*/
end_comment

end_unit

