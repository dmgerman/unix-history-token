begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vbaparam.h	1.1	86/01/21	*/
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
comment|/*   * The following constants define the fixed size map of the  * VERSAbus i/o space.  The values should reflect the range  * of i/o addresses used by all the controllers handled in  * the system as specified in the ubminit structure in ioconf.c.  */
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
comment|/* number of entries in the system page pable for i/o space */
end_comment

begin_define
define|#
directive|define
name|VBIOSIZE
value|btoc(VBIOEND-VBIOBASE)
end_define

begin_comment
comment|/*  * Page table map sizes.  *  * Current VBmap allotments are:  *	4 vd controllers	32+1 pte's  *	2 cy controllers	32+1 pte's  * Current VBMEMmap allotments are:  *	2 ace controllers	32+1 pte's  */
end_comment

begin_define
define|#
directive|define
name|VBPTSIZE
value|(((4*(32+1))+2*(32+1)+3)&~ 3)
end_define

begin_define
define|#
directive|define
name|VBMEMSIZE
value|((2*(32+1)+3)&~ 3)
end_define

end_unit

