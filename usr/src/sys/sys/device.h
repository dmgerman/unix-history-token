begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Computer Systems Engineering group at Lawrence Berkeley  * Laboratory under DARPA contract BG 91-66.  *  * %sccs.include.redist.c%  *  *	@(#)device.h	7.1 (Berkeley) %G%  *  * from: $Header: device.h,v 1.3 92/01/15 18:25:53 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Minimal device structures.  */
end_comment

begin_enum
enum|enum
name|devtype
block|{
name|DV_DULL
block|,
name|DV_DISK
block|,
name|DV_TAPE
block|,
name|DV_TTY
block|}
enum|;
end_enum

begin_struct
struct|struct
name|device
block|{
comment|/*	enum	devclass dv_class;	/* class */
name|char
modifier|*
name|dv_name
decl_stmt|;
comment|/* device name */
name|int
name|dv_unit
decl_stmt|;
comment|/* device unit number */
name|int
name|dv_flags
decl_stmt|;
comment|/* flags (copied from config) */
name|char
modifier|*
name|dv_xname
decl_stmt|;
comment|/* expanded name (name + unit) */
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
comment|/* duplicable leaf (unimplemented) */
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

end_unit

