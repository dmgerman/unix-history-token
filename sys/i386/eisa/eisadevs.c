begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by Billie Alsup (balsup@tfs.com)  * for TRW Financial Systems for use under the MACH(2.5)and OSF/1 operating  * systems.  *  * TRW Financial Systems, in accordance with their agreement with Carnegie  * Mellon University, makes this software available to CMU to distribute  * or use in any manner that they see fit as long as this message is kept with  * the software. For this reason TFS also grants any other persons or  * organisations permission to use or modify this software.  *  * TFS supplies this software to be publicly redistributed  * on the understanding that TFS is not responsible for the correct  * functioning of this software in any circumstances.  *  * $Id: eisadevs.c,v 1.1 1995/03/13 09:10:17 root Exp root $  */
end_comment

begin_comment
comment|/*  * Ported to run under FreeBSD by Julian Elischer (julian@tfs.com) Sept 1992  */
end_comment

begin_comment
comment|/* This needs to be automatically generated.. */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_comment
comment|/* isn't it a joy */
end_comment

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_comment
comment|/* to have three of these */
end_comment

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|"i386/isa/isa_device.h"
end_include

begin_include
include|#
directive|include
file|"eisaconf.h"
end_include

begin_include
include|#
directive|include
file|"bt.h"
end_include

begin_if
if|#
directive|if
name|NBT
operator|>
literal|0
end_if

begin_decl_stmt
specifier|extern
name|struct
name|isa_driver
name|btdriver
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|btintr
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|eisa_dev
name|eisa_dev
index|[]
init|=
block|{
if|#
directive|if
name|NBT
operator|>
literal|0
block|{
literal|"BUS"
block|,
literal|0x420
block|,
literal|0
block|,
operator|&
name|bio_imask
block|,
block|{
operator|-
literal|1
block|,
operator|&
name|btdriver
block|,
literal|0
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|0
block|,
name|btintr
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
block|,
block|{
literal|"BUS"
block|,
literal|0x470
block|,
literal|0
block|,
operator|&
name|bio_imask
block|,
block|{
operator|-
literal|1
block|,
operator|&
name|btdriver
block|,
literal|0
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|0
block|,
name|btintr
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
block|,
endif|#
directive|endif
comment|/* NBT> 0 */
comment|/* add your devices here */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

