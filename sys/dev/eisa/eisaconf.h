begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by Billie Alsup (balsup@tfs.com)  * for TRW Financial Systems for use under the MACH(2.5)and OSF/1 operating  * systems.  *  * TRW Financial Systems, in accordance with their agreement with Carnegie  * Mellon University, makes this software available to CMU to distribute  * or use in any manner that they see fit as long as this message is kept with  * the software. For this reason TFS also grants any other persons or  * organisations permission to use or modify this software.  *  * TFS supplies this software to be publicly redistributed  * on the understanding that TFS is not responsible for the correct  * functioning of this software in any circumstances.  *  * $Id: eisaconf.h,v 1.1 1995/03/13 09:10:17 root Exp root $  */
end_comment

begin_comment
comment|/*  * Ported to run under FreeBSD by Julian Elischer (julian@tfs.com) Sept 1992  */
end_comment

begin_define
define|#
directive|define
name|EISA_SLOTS
value|10
end_define

begin_comment
comment|/* PCI clashes with higher ones.. fix later */
end_comment

begin_struct
struct|struct
name|eisa_dev
block|{
name|char
name|productID
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|short
name|productType
decl_stmt|;
name|unsigned
name|char
name|productRevision
decl_stmt|;
name|unsigned
name|int
modifier|*
name|imask
decl_stmt|;
name|struct
name|isa_device
name|isa_dev
decl_stmt|;
block|}
struct|;
end_struct

end_unit

