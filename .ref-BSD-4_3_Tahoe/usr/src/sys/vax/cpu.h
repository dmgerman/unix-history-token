begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)cpu.h	7.5 (Berkeley) 7/9/88  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Cpu identification, from SID register.  */
end_comment

begin_union
union|union
name|cpusid
block|{
name|int
name|cpusid
decl_stmt|;
struct|struct
name|cpuany
block|{
name|u_int
label|:
literal|24
operator|,
name|cp_type
operator|:
literal|8
expr_stmt|;
block|}
name|cpuany
struct|;
struct|struct
name|cpu8600
block|{
name|u_int
name|cp_sno
range|:
literal|12
decl_stmt|,
comment|/* serial number */
name|cp_plant
range|:
literal|4
decl_stmt|,
comment|/* plant number */
name|cp_eco
range|:
literal|8
decl_stmt|,
comment|/* eco level */
name|cp_type
range|:
literal|8
decl_stmt|;
comment|/* VAX_8600 */
block|}
name|cpu8600
struct|;
struct|struct
name|cpu8200
block|{
name|u_int
name|cp_urev
range|:
literal|8
decl_stmt|,
comment|/* ucode rev */
name|cp_secp
range|:
literal|1
decl_stmt|,
comment|/* secondary patch? */
name|cp_patch
range|:
literal|10
decl_stmt|,
comment|/* patch number */
name|cp_hrev
range|:
literal|4
decl_stmt|,
comment|/* hardware rev */
name|cp_5
range|:
literal|1
decl_stmt|,
comment|/* true iff KA825 */
name|cp_type
range|:
literal|8
decl_stmt|;
comment|/* VAX_8200 */
block|}
name|cpu8200
struct|;
struct|struct
name|cpu780
block|{
name|u_int
name|cp_sno
range|:
literal|12
decl_stmt|,
comment|/* serial number */
name|cp_plant
range|:
literal|3
decl_stmt|,
comment|/* plant number */
name|cp_eco
range|:
literal|8
decl_stmt|,
comment|/* eco level */
name|cp_5
range|:
literal|1
decl_stmt|,
comment|/* true iff 785 */
name|cp_type
range|:
literal|8
decl_stmt|;
comment|/* VAX_780 */
block|}
name|cpu780
struct|;
struct|struct
name|cpu750
block|{
name|u_int
name|cp_hrev
range|:
literal|8
decl_stmt|,
comment|/* hardware rev level */
name|cp_urev
range|:
literal|8
decl_stmt|,
comment|/* ucode rev level */
range|:
literal|8
decl_stmt|,
name|cp_type
range|:
literal|8
decl_stmt|;
comment|/* VAX_750 */
block|}
name|cpu750
struct|;
struct|struct
name|cpu730
block|{
name|u_int
label|:
literal|8
operator|,
comment|/* reserved */
name|cp_urev
operator|:
literal|8
operator|,
comment|/* ucode rev level */
operator|:
literal|8
operator|,
comment|/* reserved */
name|cp_type
operator|:
literal|8
expr_stmt|;
comment|/* VAX_730 */
block|}
name|cpu730
struct|;
struct|struct
name|cpu630
block|{
name|u_int
name|cp_hrev
range|:
literal|8
decl_stmt|,
comment|/* hardware rev level */
name|cp_urev
range|:
literal|8
decl_stmt|,
comment|/* ucode rev level */
range|:
literal|8
decl_stmt|,
name|cp_type
range|:
literal|8
decl_stmt|;
comment|/* VAX_630 */
block|}
name|cpu630
struct|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Vax CPU types.  * Similar types are grouped with their earliest example.  */
end_comment

begin_define
define|#
directive|define
name|VAX_780
value|1
end_define

begin_define
define|#
directive|define
name|VAX_750
value|2
end_define

begin_define
define|#
directive|define
name|VAX_730
value|3
end_define

begin_define
define|#
directive|define
name|VAX_8600
value|4
end_define

begin_define
define|#
directive|define
name|VAX_8200
value|5
end_define

begin_define
define|#
directive|define
name|VAX_8800
value|6
end_define

begin_define
define|#
directive|define
name|VAX_8500
value|6
end_define

begin_comment
comment|/* same as 8800, 8700 */
end_comment

begin_define
define|#
directive|define
name|VAX_610
value|7
end_define

begin_comment
comment|/* uVAX I */
end_comment

begin_define
define|#
directive|define
name|VAX_630
value|8
end_define

begin_comment
comment|/* uVAX II */
end_comment

begin_define
define|#
directive|define
name|VAX_MAX
value|8
end_define

begin_comment
comment|/*  * Main IO backplane types.  * This gives us a handle on how to do autoconfiguration.  */
end_comment

begin_define
define|#
directive|define
name|IO_SBI780
value|1
end_define

begin_define
define|#
directive|define
name|IO_CMI750
value|2
end_define

begin_define
define|#
directive|define
name|IO_XXX730
value|3
end_define

begin_define
define|#
directive|define
name|IO_ABUS
value|4
end_define

begin_define
define|#
directive|define
name|IO_QBUS
value|5
end_define

begin_define
define|#
directive|define
name|IO_BI
value|6
end_define

begin_define
define|#
directive|define
name|IO_NMI
value|7
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * CPU-dependent operations.  */
end_comment

begin_struct
struct|struct
name|clockops
block|{
name|int
function_decl|(
modifier|*
name|clkstartrt
function_decl|)
parameter_list|()
function_decl|;
comment|/* start real time clock */
name|int
function_decl|(
modifier|*
name|clkread
function_decl|)
parameter_list|()
function_decl|;
comment|/* set system time from clock */
name|int
function_decl|(
modifier|*
name|clkwrite
function_decl|)
parameter_list|()
function_decl|;
comment|/* reset clock from system time */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cpuops
block|{
name|struct
name|clockops
modifier|*
name|cpu_clock
decl_stmt|;
comment|/* clock operations */
name|int
function_decl|(
modifier|*
name|cpu_memenable
function_decl|)
parameter_list|()
function_decl|;
comment|/* memory error (CRD intr) enable */
name|int
function_decl|(
modifier|*
name|cpu_memerr
function_decl|)
parameter_list|()
function_decl|;
comment|/* memory error handler */
name|int
function_decl|(
modifier|*
name|cpu_mchk
function_decl|)
parameter_list|()
function_decl|;
comment|/* machine check handler */
name|int
function_decl|(
modifier|*
name|cpu_init
function_decl|)
parameter_list|()
function_decl|;
comment|/* special initialisation, if any */
block|}
struct|;
end_struct

begin_comment
comment|/* return values from cpu_mchk */
end_comment

begin_define
define|#
directive|define
name|MCHK_PANIC
value|-1
end_define

begin_define
define|#
directive|define
name|MCHK_RECOVERED
value|0
end_define

begin_comment
comment|/*  * Per-cpu information for system.  */
end_comment

begin_struct
struct|struct
name|percpu
block|{
name|short
name|pc_cputype
decl_stmt|;
comment|/* cpu type code */
name|short
name|pc_cpuspeed
decl_stmt|;
comment|/* relative speed of cpu */
name|short
name|pc_nioa
decl_stmt|;
comment|/* number of IO adaptors/nexus blocks */
name|struct
name|iobus
modifier|*
name|pc_io
decl_stmt|;
comment|/* descriptions of IO adaptors */
name|struct
name|cpuops
modifier|*
name|pc_ops
decl_stmt|;
comment|/* per-cpu operations */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Generic description of an I/O "adaptor"  * (any top-level I/O bus visible to software  * and requiring autoconfiguration).  * The remainder of the description  * is pointed to by io_details.  */
end_comment

begin_struct
struct|struct
name|iobus
block|{
name|int
name|io_type
decl_stmt|;
comment|/* io adaptor types */
name|caddr_t
name|io_addr
decl_stmt|;
comment|/* phys address of IO adaptor */
name|int
name|io_size
decl_stmt|;
comment|/* size of an IO space */
name|caddr_t
name|io_details
decl_stmt|;
comment|/* specific to adaptor types */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Description of a main bus that maps "nexi", ala the 780 SBI.  */
end_comment

begin_struct
struct|struct
name|nexusconnect
block|{
name|short
name|psb_nnexus
decl_stmt|;
comment|/* number of nexus slots */
name|struct
name|nexus
modifier|*
name|psb_nexbase
decl_stmt|;
comment|/* base of nexus space */
name|short
name|psb_ubatype
decl_stmt|;
comment|/* type of "unibus adaptor" */
name|short
name|psb_nubabdp
decl_stmt|;
comment|/* number of bdp's per uba */
name|caddr_t
modifier|*
name|psb_umaddr
decl_stmt|;
comment|/* unibus memory addresses */
comment|/* the 750 has some slots which don't promise to tell you their types */
comment|/* if this pointer is non-zero, then you get the type from this array */
comment|/* rather than from the (much more sensible) low byte of the config register */
name|short
modifier|*
name|psb_nextype
decl_stmt|;
comment|/* botch */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Description of a BI bus configuration.  */
end_comment

begin_struct
struct|struct
name|bibus
block|{
name|struct
name|bi_node
modifier|*
name|pbi_base
decl_stmt|;
comment|/* base of node space */
comment|/* that cannot possibly be all! */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Description of a Q-bus configuration.  */
end_comment

begin_struct
struct|struct
name|qbus
block|{
name|int
name|qb_type
decl_stmt|;
comment|/* type of "unibus adaptor" */
name|int
name|qb_memsize
decl_stmt|;
comment|/* size of (used) memory, pages */
name|struct
name|pte
modifier|*
name|qb_map
decl_stmt|;
comment|/* base of map registers */
name|caddr_t
name|qb_maddr
decl_stmt|;
comment|/* "unibus" memory address */
name|caddr_t
name|qb_iopage
decl_stmt|;
comment|/* "unibus" IO page address */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|cpu
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|VAX8800
operator|||
name|VAX8200
end_if

begin_decl_stmt
name|int
name|mastercpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if multiple cpus, this identifies master */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|percpu
name|percpu
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cpuops
modifier|*
name|cpuops
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Enable realtime clock (always enabled).  */
end_comment

begin_define
define|#
directive|define
name|enablertclock
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCORE */
end_comment

end_unit

