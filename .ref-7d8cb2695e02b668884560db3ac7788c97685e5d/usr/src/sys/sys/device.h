begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)device.h	8.1 (Berkeley) %G%  *  * from: $Header: device.h,v 1.9 93/02/01 19:34:50 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Minimal device structures.  * Note that all ``system'' device types are listed here.  */
end_comment

begin_enum
enum|enum
name|devclass
block|{
name|DV_DULL
block|,
comment|/* generic, no special info */
name|DV_CPU
block|,
comment|/* CPU (carries resource utilization) */
name|DV_DISK
block|,
comment|/* disk drive (label, etc) */
name|DV_IFNET
block|,
comment|/* network interface */
name|DV_TAPE
block|,
comment|/* tape device */
name|DV_TTY
comment|/* serial line interface (???) */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|device
block|{
name|enum
name|devclass
name|dv_class
decl_stmt|;
comment|/* this device's classification */
name|struct
name|device
modifier|*
name|dv_next
decl_stmt|;
comment|/* next in list of all */
name|struct
name|cfdata
modifier|*
name|dv_cfdata
decl_stmt|;
comment|/* config data that found us */
name|int
name|dv_unit
decl_stmt|;
comment|/* device unit number */
name|char
name|dv_xname
index|[
literal|16
index|]
decl_stmt|;
comment|/* external name (name + unit) */
name|struct
name|device
modifier|*
name|dv_parent
decl_stmt|;
comment|/* pointer to parent device */
block|}
struct|;
end_struct

begin_comment
comment|/* `event' counters (use zero or more per device instance, as needed) */
end_comment

begin_struct
struct|struct
name|evcnt
block|{
name|struct
name|evcnt
modifier|*
name|ev_next
decl_stmt|;
comment|/* linked list */
name|struct
name|device
modifier|*
name|ev_dev
decl_stmt|;
comment|/* associated device */
name|int
name|ev_count
decl_stmt|;
comment|/* how many have occurred */
name|char
name|ev_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* what to call them (systat display) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Configuration data (i.e., data placed in ioconf.c).  */
end_comment

begin_struct
struct|struct
name|cfdata
block|{
name|struct
name|cfdriver
modifier|*
name|cf_driver
decl_stmt|;
comment|/* config driver */
name|short
name|cf_unit
decl_stmt|;
comment|/* unit number */
name|short
name|cf_fstate
decl_stmt|;
comment|/* finding state (below) */
name|int
modifier|*
name|cf_loc
decl_stmt|;
comment|/* locators (machine dependent) */
name|int
name|cf_flags
decl_stmt|;
comment|/* flags from config */
name|short
modifier|*
name|cf_parents
decl_stmt|;
comment|/* potential parents */
name|void
function_decl|(
modifier|*
modifier|*
name|cf_ivstubs
function_decl|)
parameter_list|()
function_decl|;
comment|/* config-generated vectors, if any */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FSTATE_NOTFOUND
value|0
end_define

begin_comment
comment|/* has not been found */
end_comment

begin_define
define|#
directive|define
name|FSTATE_FOUND
value|1
end_define

begin_comment
comment|/* has been found */
end_comment

begin_define
define|#
directive|define
name|FSTATE_STAR
value|2
end_define

begin_comment
comment|/* duplicable */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*cfmatch_t
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|,
expr|struct
name|cfdata
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/*  * `configuration' driver (what the machine-independent autoconf uses).  * As devices are found, they are applied against all the potential matches.  * The one with the best match is taken, and a device structure (plus any  * other data desired) is allocated.  Pointers to these are placed into  * an array of pointers.  The array itself must be dynamic since devices  * can be found long after the machine is up and running.  */
end_comment

begin_struct
struct|struct
name|cfdriver
block|{
name|void
modifier|*
modifier|*
name|cd_devs
decl_stmt|;
comment|/* devices found */
name|char
modifier|*
name|cd_name
decl_stmt|;
comment|/* device name */
name|cfmatch_t
name|cd_match
decl_stmt|;
comment|/* returns a match level */
name|void
argument_list|(
argument|*cd_attach
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|,
expr|struct
name|device
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
name|enum
name|devclass
name|cd_class
decl_stmt|;
comment|/* device classification */
name|size_t
name|cd_devsize
decl_stmt|;
comment|/* size of dev data (for malloc) */
name|void
modifier|*
name|cd_aux
decl_stmt|;
comment|/* additional driver, if any */
name|int
name|cd_ndevs
decl_stmt|;
comment|/* size of cd_devs array */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Configuration printing functions, and their return codes.  The second  * argument is NULL if the device was configured; otherwise it is the name  * of the parent device.  The return value is ignored if the device was  * configured, so most functions can return UNCONF unconditionally.  */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*cfprint_t
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|QUIET
value|0
end_define

begin_comment
comment|/* print nothing */
end_comment

begin_define
define|#
directive|define
name|UNCONF
value|1
end_define

begin_comment
comment|/* print " not configured\n" */
end_comment

begin_define
define|#
directive|define
name|UNSUPP
value|2
end_define

begin_comment
comment|/* print " not supported\n" */
end_comment

begin_comment
comment|/*  * Pseudo-device attach information (function + number of pseudo-devs).  */
end_comment

begin_struct
struct|struct
name|pdevinit
block|{
name|void
argument_list|(
argument|*pdev_attach
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
name|int
name|pdev_count
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|device
modifier|*
name|alldevs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of list of all devices */
end_comment

begin_decl_stmt
name|struct
name|evcnt
modifier|*
name|allevents
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of list of all events */
end_comment

begin_decl_stmt
name|struct
name|cfdata
modifier|*
name|config_search
name|__P
argument_list|(
operator|(
name|cfmatch_t
operator|,
expr|struct
name|device
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cfdata
modifier|*
name|config_rootsearch
name|__P
argument_list|(
operator|(
name|cfmatch_t
operator|,
name|char
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|config_found
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|,
name|void
operator|*
operator|,
name|cfprint_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|config_rootfound
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|config_attach
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|,
expr|struct
name|cfdata
operator|*
operator|,
name|void
operator|*
operator|,
name|cfprint_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|evcnt_attach
name|__P
argument_list|(
operator|(
expr|struct
name|device
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
expr|struct
name|evcnt
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

