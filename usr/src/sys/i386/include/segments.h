begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * 386 Segmentation Data Structures and definitions  *	William F. Jolitz (william@ernie.berkeley.edu) 6/20/1989  */
end_comment

begin_comment
comment|/*  * Selectors  */
end_comment

begin_define
define|#
directive|define
name|ISPL
parameter_list|(
name|s
parameter_list|)
value|((s)&3)
end_define

begin_comment
comment|/* what is the priority level of a selector */
end_comment

begin_define
define|#
directive|define
name|SEL_KPL
value|0
end_define

begin_comment
comment|/* kernel priority level */
end_comment

begin_define
define|#
directive|define
name|SEL_UPL
value|3
end_define

begin_comment
comment|/* user priority level */
end_comment

begin_define
define|#
directive|define
name|ISLDT
parameter_list|(
name|s
parameter_list|)
value|((s)&SEL_LDT)
end_define

begin_comment
comment|/* is it local or global */
end_comment

begin_define
define|#
directive|define
name|SEL_LDT
value|4
end_define

begin_comment
comment|/* local descriptor table */
end_comment

begin_define
define|#
directive|define
name|IDXSEL
parameter_list|(
name|s
parameter_list|)
value|(((s)>>3)& 0x1fff)
end_define

begin_comment
comment|/* index of selector */
end_comment

begin_define
define|#
directive|define
name|LSEL
parameter_list|(
name|s
parameter_list|,
name|r
parameter_list|)
value|(((s)<<3) | SEL_LDT | r)
end_define

begin_comment
comment|/* a local selector */
end_comment

begin_define
define|#
directive|define
name|GSEL
parameter_list|(
name|s
parameter_list|,
name|r
parameter_list|)
value|(((s)<<3) | r)
end_define

begin_comment
comment|/* a global selector */
end_comment

begin_comment
comment|/*  * Memory and System segment descriptors  */
end_comment

begin_struct
struct|struct
name|segment_descriptor
block|{
name|unsigned
name|sd_lolimit
range|:
literal|16
decl_stmt|;
comment|/* segment extent (lsb) */
name|unsigned
name|sd_lobase
range|:
literal|24
decl_stmt|;
comment|/* segment base address (lsb) */
name|unsigned
name|sd_type
range|:
literal|5
decl_stmt|;
comment|/* segment type */
name|unsigned
name|sd_dpl
range|:
literal|2
decl_stmt|;
comment|/* segment descriptor priority level */
name|unsigned
name|sd_p
range|:
literal|1
decl_stmt|;
comment|/* segment descriptor present */
name|unsigned
name|sd_hilimit
range|:
literal|4
decl_stmt|;
comment|/* segment extent (msb) */
name|unsigned
name|sd_xx
range|:
literal|2
decl_stmt|;
comment|/* unused */
name|unsigned
name|sd_def32
range|:
literal|1
decl_stmt|;
comment|/* default 32 vs 16 bit size */
name|unsigned
name|sd_gran
range|:
literal|1
decl_stmt|;
comment|/* limit granularity (byte/page units)*/
name|unsigned
name|sd_hibase
range|:
literal|8
decl_stmt|;
comment|/* segment base address  (msb) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Gate descriptors (e.g. indirect descriptors)  */
end_comment

begin_struct
struct|struct
name|gate_descriptor
block|{
name|unsigned
name|gd_looffset
range|:
literal|16
decl_stmt|;
comment|/* gate offset (lsb) */
name|unsigned
name|gd_selector
range|:
literal|16
decl_stmt|;
comment|/* gate segment selector */
name|unsigned
name|gd_stkcpy
range|:
literal|5
decl_stmt|;
comment|/* number of stack wds to cpy */
name|unsigned
name|gd_xx
range|:
literal|3
decl_stmt|;
comment|/* unused */
name|unsigned
name|gd_type
range|:
literal|5
decl_stmt|;
comment|/* segment type */
name|unsigned
name|gd_dpl
range|:
literal|2
decl_stmt|;
comment|/* segment descriptor priority level */
name|unsigned
name|gd_p
range|:
literal|1
decl_stmt|;
comment|/* segment descriptor present */
name|unsigned
name|gd_hioffset
range|:
literal|16
decl_stmt|;
comment|/* gate offset (msb) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Generic descriptor  */
end_comment

begin_union
union|union
name|descriptor
block|{
name|struct
name|segment_descriptor
name|sd
decl_stmt|;
name|struct
name|gate_descriptor
name|gd
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|d_type
value|gd.gd_type
end_define

begin_comment
comment|/* system segments and gate types */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSNULL
value|0
end_define

begin_comment
comment|/* system null */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS286TSS
value|1
end_define

begin_comment
comment|/* system 286 TSS available */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSLDT
value|2
end_define

begin_comment
comment|/* system local descriptor table */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS286BSY
value|3
end_define

begin_comment
comment|/* system 286 TSS busy */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS286CGT
value|4
end_define

begin_comment
comment|/* system 286 call gate */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSTASKGT
value|5
end_define

begin_comment
comment|/* system task gate */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS286IGT
value|6
end_define

begin_comment
comment|/* system 286 interrupt gate */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS286TGT
value|7
end_define

begin_comment
comment|/* system 286 trap gate */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSNULL2
value|8
end_define

begin_comment
comment|/* system null again */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS386TSS
value|9
end_define

begin_comment
comment|/* system 386 TSS available */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSNULL3
value|10
end_define

begin_comment
comment|/* system null again */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS386BSY
value|11
end_define

begin_comment
comment|/* system 386 TSS busy */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS386CGT
value|12
end_define

begin_comment
comment|/* system 386 call gate */
end_comment

begin_define
define|#
directive|define
name|SDT_SYSNULL4
value|13
end_define

begin_comment
comment|/* system null again */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS386IGT
value|14
end_define

begin_comment
comment|/* system 386 interrupt gate */
end_comment

begin_define
define|#
directive|define
name|SDT_SYS386TGT
value|15
end_define

begin_comment
comment|/* system 386 trap gate */
end_comment

begin_comment
comment|/* memory segment types */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMRO
value|16
end_define

begin_comment
comment|/* memory read only */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMROA
value|17
end_define

begin_comment
comment|/* memory read only accessed */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMRW
value|18
end_define

begin_comment
comment|/* memory read write */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMRWA
value|19
end_define

begin_comment
comment|/* memory read write accessed */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMROD
value|20
end_define

begin_comment
comment|/* memory read only expand dwn limit */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMRODA
value|21
end_define

begin_comment
comment|/* memory read only expand dwn limit accessed */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMRWD
value|22
end_define

begin_comment
comment|/* memory read write expand dwn limit */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMRWDA
value|23
end_define

begin_comment
comment|/* memory read write expand dwn limit acessed */
end_comment

begin_define
define|#
directive|define
name|SDT_MEME
value|24
end_define

begin_comment
comment|/* memory execute only */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMEA
value|25
end_define

begin_comment
comment|/* memory execute only accessed */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMER
value|26
end_define

begin_comment
comment|/* memory execute read */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMERA
value|27
end_define

begin_comment
comment|/* memory execute read accessed */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMEC
value|28
end_define

begin_comment
comment|/* memory execute only conforming */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMEAC
value|29
end_define

begin_comment
comment|/* memory execute only accessed conforming */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMERC
value|30
end_define

begin_comment
comment|/* memory execute read conforming */
end_comment

begin_define
define|#
directive|define
name|SDT_MEMERAC
value|31
end_define

begin_comment
comment|/* memory execute read accessed conforming */
end_comment

begin_comment
comment|/* is memory segment descriptor pointer ? */
end_comment

begin_define
define|#
directive|define
name|ISMEMSDP
parameter_list|(
name|s
parameter_list|)
value|((s->d_type)>= SDT_MEMRO&& (s->d_type)<= SDT_MEMERAC)
end_define

begin_comment
comment|/* is 286 gate descriptor pointer ? */
end_comment

begin_define
define|#
directive|define
name|IS286GDP
parameter_list|(
name|s
parameter_list|)
value|(((s->d_type)>= SDT_SYS286CGT \&& (s->d_type)< SDT_SYS286TGT))
end_define

begin_comment
comment|/* is 386 gate descriptor pointer ? */
end_comment

begin_define
define|#
directive|define
name|IS386GDP
parameter_list|(
name|s
parameter_list|)
value|(((s->d_type)>= SDT_SYS386CGT \&& (s->d_type)< SDT_SYS386TGT))
end_define

begin_comment
comment|/* is gate descriptor pointer ? */
end_comment

begin_define
define|#
directive|define
name|ISGDP
parameter_list|(
name|s
parameter_list|)
value|(IS286GDP(s) || IS386GDP(s))
end_define

begin_comment
comment|/* is segment descriptor pointer ? */
end_comment

begin_define
define|#
directive|define
name|ISSDP
parameter_list|(
name|s
parameter_list|)
value|(ISMEMSDP(s) || !ISGDP(s))
end_define

begin_comment
comment|/* is system segment descriptor pointer ? */
end_comment

begin_define
define|#
directive|define
name|ISSYSSDP
parameter_list|(
name|s
parameter_list|)
value|(!ISMEMSDP(s)&& !ISGDP(s))
end_define

begin_comment
comment|/*  * Software definitions are in this convenient format,  * which are translated into inconvenient segment descriptors  * when needed to be used by the 386 hardware  */
end_comment

begin_struct
struct|struct
name|soft_segment_descriptor
block|{
name|unsigned
name|ssd_base
decl_stmt|;
comment|/* segment base address  */
name|unsigned
name|ssd_limit
decl_stmt|;
comment|/* segment extent */
name|unsigned
name|ssd_type
range|:
literal|5
decl_stmt|;
comment|/* segment type */
name|unsigned
name|ssd_dpl
range|:
literal|2
decl_stmt|;
comment|/* segment descriptor priority level */
name|unsigned
name|ssd_p
range|:
literal|1
decl_stmt|;
comment|/* segment descriptor present */
name|unsigned
name|ssd_xx
range|:
literal|4
decl_stmt|;
comment|/* unused */
name|unsigned
name|ssd_xx1
range|:
literal|2
decl_stmt|;
comment|/* unused */
name|unsigned
name|ssd_def32
range|:
literal|1
decl_stmt|;
comment|/* default 32 vs 16 bit size */
name|unsigned
name|ssd_gran
range|:
literal|1
decl_stmt|;
comment|/* limit granularity (byte/page units)*/
block|}
struct|;
end_struct

begin_extern
extern|extern ssdtosd(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* to decode a ssd */
end_comment

begin_extern
extern|extern sdtossd(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* to encode a sd */
end_comment

begin_comment
comment|/*  * region descriptors, used to load gdt/idt tables before segments yet exist  */
end_comment

begin_struct
struct|struct
name|region_descriptor
block|{
name|unsigned
name|rd_limit
range|:
literal|16
decl_stmt|;
comment|/* segment extent */
name|char
modifier|*
name|rd_base
decl_stmt|;
comment|/* base address  */
block|}
struct|;
end_struct

end_unit

