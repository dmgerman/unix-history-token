begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)vbaparam.h	7.2 (Berkeley) 6/29/88  */
end_comment

begin_comment
comment|/*  * Parameters related to the VERSAbus i/o configuration.  */
end_comment

begin_comment
comment|/*  * VERSAbus i/o devices use either memory mapped interfaces  * or mapped i/o register banks, or some of both.  Page tables  * are allocated at boot time by each device driver, as needed.  * VMEMmap is used to map a fixed size portion of the VERSAbus  * i/o space, while VMEMmap1 maps dynamically defined portions  * for devices which utilize shared i/o memory.  VBmap is used  * for mapping kernel intermediate buffers for DMA devices which  * are incapable of utilizing user virtual addresses or which  * require page aligned i/o buffers.  The size of the VMEMmap1  * VBmap tables must be large enough for the needs of all devices  * in the system.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|VMEMmap
index|[]
decl_stmt|,
name|VMEMmap1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|caddr_t
name|vmem1
decl_stmt|,
name|vmemend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|VBmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|caddr_t
name|vbbase
decl_stmt|,
name|vbend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The following macros relate to the segmentation of the VERSAbus  * i/o space.  *  * The VERSAbus adapter segments the i/o space (as seen by the cpu)  * into three regions.  Cpu accesses to the upper 64Kb of the i/o space  * generate VERSAbus cycles with a 16-bit address and a non-privileged  * short i/o space address modifier.  Accesses to the next 1Mb - 64Kb  * generate 24-bit addresses and a non-privileged standard address  * modifier.  Accesses to the remainder of the 1Gb i/o space generate  * 32-bit addresses with a non-privileged extended address modifier.  * Beware that 32-bit addresses generated from this region always have  * zero in the upper 2 bits; e.g. a reference to physical address fe000000  * results in a VERSAbus address of 3e000000.  */
end_comment

begin_define
define|#
directive|define
name|VBIO16BIT
parameter_list|(
name|a
parameter_list|)
value|((unsigned)0xfffe0000<= ((unsigned)(a)))
end_define

begin_define
define|#
directive|define
name|VBIO24BIT
parameter_list|(
name|a
parameter_list|)
value|((unsigned)0xff000000<= ((unsigned)(a))&& \ 			 ((unsigned)(a))< (unsigned)0xfffe0000)
end_define

begin_define
define|#
directive|define
name|VBIO32BIT
parameter_list|(
name|a
parameter_list|)
value|(((unsigned)(a))< (unsigned)0xff000000)
end_define

begin_comment
comment|/*   * The following constants define the fixed size map of the  * VERSAbus i/o space.  The values should reflect the range  * of i/o addresses used by all the controllers unprepared  * to allocate and initialize their own page maps.  */
end_comment

begin_define
define|#
directive|define
name|VBIOBASE
value|0xfff00000
end_define

begin_comment
comment|/* base of VERSAbus address space */
end_comment

begin_define
define|#
directive|define
name|VBIOEND
value|0xffffee45
end_define

begin_comment
comment|/* last address in mapped space */
end_comment

begin_comment
comment|/* number of entries in the system page table for i/o space */
end_comment

begin_define
define|#
directive|define
name|VBIOSIZE
value|btoc(VBIOEND-VBIOBASE)
end_define

begin_comment
comment|/* is device in mapped region */
end_comment

begin_define
define|#
directive|define
name|VBIOMAPPED
parameter_list|(
name|a
parameter_list|)
value|((unsigned)VBIOBASE<= ((unsigned)(a))&& \ 			 ((unsigned)(a))<= (unsigned)VBIOEND)
end_define

begin_define
define|#
directive|define
name|vboff
parameter_list|(
name|addr
parameter_list|)
value|((int)(((caddr_t)(addr)) - VBIOBASE))
end_define

end_unit

