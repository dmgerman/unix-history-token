begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California  * All rights reserved.  *  * This code is derived from the null layer of  * John Heidemann of the UCLA Ficus project and  * the Jan-Simon Pendry's loopback file system.  *  * %sccs.include.redist.c%  *  *	@(#)null_vnops.c	1.3 (Berkeley) %G%  *  * Ancestors:  *	@(#)lofs_vnops.c	1.2 (Berkeley) 6/18/92  *	$Id: lofs_vnops.c,v 1.11 1992/05/30 10:05:43 jsp Exp jsp $  *	...and...  *	@(#)null_vnodeops.c 1.20 92/07/07 UCLA Ficus project  */
end_comment

begin_comment
comment|/*  * Null Layer  *  * The null layer duplicates a portion of the file system  * name space under a new name.  In this respect, it is  * similar to the loopback file system.  It differs from  * the loopback fs in two respects:  it is implemented using  * a bypass operation, and it's "null-nodes" stack above  * all lower-layer vnodes, not just over directory vnodes.  *  * The null layer is the minimum file system layer,  * simply bypassing all possible operations to the lower layer  * for processing there.  All but vop_getattr, _inactive, _reclaim,  * and _print are bypassed.  *  * Vop_getattr is not bypassed so that we can change the fsid being  * returned.  Vop_{inactive,reclaim} are bypassed so that  * they can handle freeing null-layer specific data.  * Vop_print is not bypassed for debugging.  *  * NEEDSWORK: Describe methods to invoke operations on the lower layer  * (bypass vs. VOP).  */
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

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/namei.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<lofs/lofs.h>
end_include

begin_decl_stmt
name|int
name|null_bug_bypass
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for debugging: enables bypass printf'ing */
end_comment

begin_comment
comment|/*  * This is the 10-Apr-92 bypass routine.  *    This version has been optimized for speed, throwing away some  * safety checks.  It should still always work, but it's not as  * robust to programmer errors.  *    Define SAFETY to include some error checking code.  *  * In general, we map all vnodes going down and unmap them on the way back.  * As an exception to this, vnodes can be marked "unmapped" by setting  * the Nth bit in operation's vdesc_flags.  *  * Also, some BSD vnode operations have the side effect of vrele'ing  * their arguments.  With stacking, the reference counts are held  * by the upper node, not the lower one, so we must handle these  * side-effects here.  This is not of concern in Sun-derived systems  * since there are no such side-effects.  *  * This makes the following assumptions:  * - only one returned vpp  * - no INOUT vpp's (Sun's vop_open has one of these)  * - the vnode operation vector of the first vnode should be used  *   to determine what implementation of the op should be invoked  * - all mapped vnodes are of our vnode-type (NEEDSWORK:  *   problems on rmdir'ing mount points and renaming?)  */
end_comment

begin_function
name|int
name|null_bypass
parameter_list|(
name|ap
parameter_list|)
name|struct
name|nvop_generic_args
modifier|*
name|ap
decl_stmt|;
block|{
specifier|register
name|int
name|this_vp_p
decl_stmt|;
name|int
name|error
decl_stmt|;
name|struct
name|vnode
modifier|*
name|old_vps
index|[
name|VDESC_MAX_VPS
index|]
decl_stmt|;
name|struct
name|vnode
modifier|*
modifier|*
name|vps_p
index|[
name|VDESC_MAX_VPS
index|]
decl_stmt|;
name|struct
name|vnode
modifier|*
modifier|*
modifier|*
name|vppp
decl_stmt|;
name|struct
name|vnodeop_desc
modifier|*
name|descp
init|=
name|ap
operator|->
name|a_desc
decl_stmt|;
name|int
name|maps
decl_stmt|,
name|reles
decl_stmt|,
name|i
decl_stmt|;
if|if
condition|(
name|null_bug_bypass
condition|)
name|printf
argument_list|(
literal|"null_bypass: %s\n"
argument_list|,
name|descp
operator|->
name|vdesc_name
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SAFETY
comment|/* 	 * We require at least one vp. 	 */
if|if
condition|(
name|descp
operator|->
name|vdesc_vp_offsets
operator|==
name|NULL
operator|||
name|descp
operator|->
name|vdesc_vp_offsets
index|[
literal|0
index|]
operator|==
name|VDESC_NO_OFFSET
condition|)
name|panic
argument_list|(
literal|"null_bypass: no vp's in map.\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Map the vnodes going in. 	 * Later, we'll invoke the operation based on 	 * the first mapped vnode's operation vector. 	 */
name|maps
operator|=
name|descp
operator|->
name|vdesc_flags
expr_stmt|;
name|reles
operator|=
name|descp
operator|->
name|vdesc_rele_flags
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|VDESC_MAX_VPS
condition|;
name|maps
operator|>>=
literal|1
operator|,
name|reles
operator|>>=
literal|1
operator|,
name|i
operator|++
control|)
block|{
if|if
condition|(
name|descp
operator|->
name|vdesc_vp_offsets
index|[
name|i
index|]
operator|==
name|VDESC_NO_OFFSET
condition|)
break|break;
comment|/* bail out at end of list */
if|if
condition|(
name|maps
operator|&
literal|1
condition|)
comment|/* skip vps that aren't to be mapped */
continue|continue;
name|vps_p
index|[
name|i
index|]
operator|=
name|this_vp_p
operator|=
name|VOPARG_OFFSETTO
argument_list|(
expr|struct
name|vnode
operator|*
operator|*
argument_list|,
name|descp
operator|->
name|vdesc_vp_offsets
index|[
name|i
index|]
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|old_vps
index|[
name|i
index|]
operator|=
operator|*
name|this_vp_p
expr_stmt|;
operator|*
operator|(
name|vps_p
index|[
name|i
index|]
operator|)
operator|=
name|NULLTOLOWERVP
argument_list|(
name|VTONULLNODE
argument_list|(
operator|*
name|this_vp_p
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|reles
operator|&
literal|1
condition|)
name|VREF
argument_list|(
operator|*
name|this_vp_p
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|/* 	 * Call the operation on the lower layer 	 * with the modified argument structure. 	 */
name|error
operator|=
name|VCALL
argument_list|(
operator|*
operator|(
name|vps_p
index|[
literal|0
index|]
operator|)
argument_list|,
name|descp
operator|->
name|vdesc_offset
argument_list|,
name|ap
argument_list|)
expr_stmt|;
comment|/* 	 * Maintain the illusion of call-by-value 	 * by restoring vnodes in the argument structure 	 * to their original value. 	 */
name|maps
operator|=
name|descp
operator|->
name|vdesc_flags
expr_stmt|;
name|reles
operator|=
name|descp
operator|->
name|vdesc_rele_flags
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|VDESC_MAX_VPS
condition|;
name|maps
operator|>>=
literal|1
operator|,
name|i
operator|++
control|)
block|{
if|if
condition|(
name|descp
operator|->
name|vdesc_vp_offsets
index|[
name|i
index|]
operator|==
name|VDESC_NO_OFFSET
condition|)
break|break;
comment|/* bail out at end of list */
if|if
condition|(
name|maps
operator|&
literal|1
condition|)
comment|/* skip vps that aren't to be mapped */
continue|continue;
operator|*
operator|(
name|vps_p
index|[
name|i
index|]
operator|)
operator|=
name|old_vps
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|reles
operator|&
literal|1
condition|)
name|vrele
argument_list|(
operator|*
operator|(
name|vps_p
index|[
name|i
index|]
operator|)
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|/* 	 * Map the possible out-going vpp. 	 */
if|if
condition|(
name|descp
operator|->
name|vdesc_vpp_offset
operator|!=
name|VDESC_NO_OFFSET
operator|&&
operator|!
operator|(
name|descp
operator|->
name|vdesc_flags
operator|&
name|VDESC_NOMAP_VPP
operator|)
operator|&&
operator|!
name|error
condition|)
block|{
name|vppp
operator|=
name|VOPARG_OFFSETTO
argument_list|(
expr|struct
name|vnode
operator|*
operator|*
operator|*
argument_list|,
name|descp
operator|->
name|vdesc_vpp_offset
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|error
operator|=
name|make_null_node
argument_list|(
name|old_vps
index|[
literal|0
index|]
operator|->
name|v_mount
argument_list|,
operator|*
operator|*
name|vppp
argument_list|,
operator|*
name|vppp
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  *  We handle getattr to change the fsid.  */
end_comment

begin_function
name|int
name|null_getattr
parameter_list|(
name|ap
parameter_list|)
name|struct
name|nvop_getattr_args
modifier|*
name|ap
decl_stmt|;
block|{
name|int
name|error
decl_stmt|;
if|if
condition|(
name|error
operator|=
name|null_bypass
argument_list|(
name|ap
argument_list|)
condition|)
return|return
name|error
return|;
comment|/* Requires that arguments be restored. */
name|ap
operator|->
name|a_vap
operator|->
name|va_fsid
operator|=
name|ap
operator|->
name|a_vp
operator|->
name|v_mount
operator|->
name|mnt_stat
operator|.
name|f_fsid
operator|.
name|val
index|[
literal|0
index|]
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_if
unit|null_rename (ap) 	struct vop_rename_args *ap; { 	USES_VOP_RENAME; 	struct vnode *fvp, *tvp; 	struct vnode *tdvp;
if|#
directive|if
literal|0
end_if

begin_endif
unit|struct vnode *fsvp, *tsvp;
endif|#
directive|endif
end_endif

begin_ifdef
unit|int error;
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
end_ifdef

begin_comment
unit|printf("null_rename(fdvp = %x->%x)\n", ap->a_fdvp, NULLTOLOWERVP(ap->a_fdvp));
comment|/*printf("null_rename(tdvp = %x->%x)\n", tndp->ni_dvp, NULLTOLOWERVP(tndp->ni_dvp));*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
end_ifdef

begin_endif
unit|printf("null_rename - switch source dvp\n");
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	 * Switch source directory to point to lofsed vnode 	 */
end_comment

begin_ifdef
unit|PUSHREF(fdvp, ap->a_fdvp); 	VREF(ap->a_fdvp);
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
end_ifdef

begin_endif
unit|printf("null_rename - switch source vp\n");
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	 * And source object if it is lofsed... 	 */
end_comment

begin_if
unit|fvp = ap->a_fvp; 	if (fvp&& fvp->v_op == null_vnodeop_p) { 		ap->a_fvp = NULLTOLOWERVP(fvp); 		VREF(ap->a_fvp); 	} else { 		fvp = 0; 	}
if|#
directive|if
literal|0
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
end_ifdef

begin_endif
unit|printf("null_rename - switch source start vp\n");
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	 * And source startdir object if it is lofsed... 	 */
end_comment

begin_endif
unit|fsvp = fndp->ni_startdir; 	if (fsvp&& fsvp->v_op == null_vnodeop_p) { 		fndp->ni_startdir = NULLTOLOWERVP(fsvp); 		VREF(fndp->ni_startdir); 	} else { 		fsvp = 0; 	}
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
end_ifdef

begin_endif
unit|printf("null_rename - switch target dvp\n");
endif|#
directive|endif
end_endif

begin_comment
comment|/*  	 * Switch target directory to point to lofsed vnode 	 */
end_comment

begin_ifdef
unit|tdvp = ap->a_tdvp; 	if (tdvp&& tdvp->v_op == null_vnodeop_p) { 		ap->a_tdvp = NULLTOLOWERVP(tdvp); 		VREF(ap->a_tdvp); 	} else { 		tdvp = 0; 	}
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
end_ifdef

begin_endif
unit|printf("null_rename - switch target vp\n");
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	 * And target object if it is lofsed... 	 */
end_comment

begin_if
unit|tvp = ap->a_tvp; 	if (tvp&& tvp->v_op == null_vnodeop_p) { 		ap->a_tvp = NULLTOLOWERVP(tvp); 		VREF(ap->a_tvp); 	} else { 		tvp = 0; 	}
if|#
directive|if
literal|0
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
end_ifdef

begin_endif
unit|printf("null_rename - switch target start vp\n");
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	 * And target startdir object if it is lofsed... 	 */
end_comment

begin_endif
unit|tsvp = tndp->ni_startdir; 	if (tsvp&& tsvp->v_op == null_vnodeop_p) { 		tndp->ni_startdir = NULLTOLOWERVP(fsvp); 		VREF(tndp->ni_startdir); 	} else { 		tsvp = 0; 	}
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
end_ifdef

begin_endif
unit|printf("null_rename - VOP_RENAME(%x, %x, %x, %x)\n", 		ap->a_fdvp, ap->a_fvp, ap->a_tdvp, ap->a_tvp); 	vprint("ap->a_fdvp", ap->a_fdvp); 	vprint("ap->a_fvp", ap->a_fvp); 	vprint("ap->a_tdvp", ap->a_tdvp); 	if (ap->a_tvp) vprint("ap->a_tvp", ap->a_tvp); 	DELAY(16000000);
endif|#
directive|endif
end_endif

begin_comment
unit|error = VOP_RENAME(ap->a_fdvp, ap->a_fvp, ap->a_fcnp, ap->a_tdvp, ap->a_tvp, ap->a_tcnp);
comment|/* 	 * Put everything back... 	 */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
end_ifdef

begin_endif
unit|printf("null_rename - restore target startdir\n");
endif|#
directive|endif
end_endif

begin_endif
unit|if (tsvp) { 		if (tndp->ni_startdir) 			vrele(tndp->ni_startdir); 		tndp->ni_startdir = tsvp; 	}
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
end_ifdef

begin_endif
unit|printf("null_rename - restore target vp\n");
endif|#
directive|endif
end_endif

begin_ifdef
unit|if (tvp) { 		ap->a_tvp = tvp; 		vrele(ap->a_tvp); 	}
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
end_ifdef

begin_endif
unit|printf("null_rename - restore target dvp\n");
endif|#
directive|endif
end_endif

begin_if
unit|if (tdvp) { 		ap->a_tdvp = tdvp; 		vrele(ap->a_tdvp); 	}
if|#
directive|if
literal|0
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
end_ifdef

begin_endif
unit|printf("null_rename - restore source startdir\n");
endif|#
directive|endif
end_endif

begin_endif
unit|if (fsvp) { 		if (fndp->ni_startdir) 			vrele(fndp->ni_startdir); 		fndp->ni_startdir = fsvp; 	}
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
end_ifdef

begin_endif
unit|printf("null_rename - restore source vp\n");
endif|#
directive|endif
end_endif

begin_ifdef
unit|if (fvp) { 		ap->a_fvp = fvp; 		vrele(ap->a_fvp); 	}
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
end_ifdef

begin_endif
unit|printf("null_rename - restore source dvp\n");
endif|#
directive|endif
end_endif

begin_endif
unit|POP(fdvp, ap->a_fdvp); 	vrele(ap->a_fdvp);  	return (error); }
endif|#
directive|endif
end_endif

begin_function
name|int
name|null_inactive
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_inactive_args
modifier|*
name|ap
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
name|printf
argument_list|(
literal|"null_inactive(ap->a_vp = %x->%x)\n"
argument_list|,
name|ap
operator|->
name|a_vp
argument_list|,
name|NULLTOLOWERVP
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Do nothing (and _don't_ bypass). 	 * Wait to vrele lowervp until reclaim, 	 * so that until then our null_node is in the 	 * cache and reusable. 	 * 	 * NEEDSWORK: Someday, consider inactive'ing 	 * the lowervp and then trying to reactivate it 	 * like they do in the name lookup cache code. 	 * That's too much work for now. 	 */
return|return
literal|0
return|;
block|}
end_function

begin_macro
name|null_reclaim
argument_list|(
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vop_reclaim_args
modifier|*
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|USES_VOP_RECLAIM
expr_stmt|;
name|struct
name|vnode
modifier|*
name|targetvp
decl_stmt|;
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
name|printf
argument_list|(
literal|"null_reclaim(ap->a_vp = %x->%x)\n"
argument_list|,
name|ap
operator|->
name|a_vp
argument_list|,
name|NULLTOLOWERVP
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|remque
argument_list|(
name|VTONULLNODE
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|)
argument_list|)
expr_stmt|;
comment|/* NEEDSWORK: What? */
name|vrele
argument_list|(
name|NULLTOLOWERVP
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|)
argument_list|)
expr_stmt|;
comment|/* release lower layer */
name|FREE
argument_list|(
name|ap
operator|->
name|a_vp
operator|->
name|v_data
argument_list|,
name|M_TEMP
argument_list|)
expr_stmt|;
name|ap
operator|->
name|a_vp
operator|->
name|v_data
operator|=
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|null_bmap
argument_list|(
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vop_bmap_args
modifier|*
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|USES_VOP_BMAP
expr_stmt|;
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
name|printf
argument_list|(
literal|"null_bmap(ap->a_vp = %x->%x)\n"
argument_list|,
name|ap
operator|->
name|a_vp
argument_list|,
name|NULLTOLOWERVP
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|VOP_BMAP
argument_list|(
name|NULLTOLOWERVP
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|)
argument_list|,
name|ap
operator|->
name|a_bn
argument_list|,
name|ap
operator|->
name|a_vpp
argument_list|,
name|ap
operator|->
name|a_bnp
argument_list|)
return|;
block|}
end_block

begin_macro
name|null_strategy
argument_list|(
argument|ap
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vop_strategy_args
modifier|*
name|ap
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|USES_VOP_STRATEGY
expr_stmt|;
name|int
name|error
decl_stmt|;
name|struct
name|vnode
modifier|*
name|savedvp
decl_stmt|;
ifdef|#
directive|ifdef
name|NULLFS_DIAGNOSTIC
name|printf
argument_list|(
literal|"null_strategy(vp = %x->%x)\n"
argument_list|,
name|ap
operator|->
name|a_bp
operator|->
name|b_vp
argument_list|,
name|NULLTOLOWERVP
argument_list|(
name|ap
operator|->
name|a_bp
operator|->
name|b_vp
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|savedvp
operator|=
name|ap
operator|->
name|a_bp
operator|->
name|b_vp
expr_stmt|;
name|error
operator|=
name|VOP_STRATEGY
argument_list|(
name|ap
operator|->
name|a_bp
argument_list|)
expr_stmt|;
name|ap
operator|->
name|a_bp
operator|->
name|b_vp
operator|=
name|savedvp
expr_stmt|;
return|return
name|error
return|;
block|}
end_block

begin_function
name|int
name|null_print
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_print_args
modifier|*
name|ap
decl_stmt|;
block|{
specifier|register
name|struct
name|vnode
modifier|*
name|vp
init|=
name|ap
operator|->
name|a_vp
decl_stmt|;
name|printf
argument_list|(
literal|"tag VT_NULLFS, vp=%x, lowervp=%x\n"
argument_list|,
name|vp
argument_list|,
name|NULLTOLOWERVP
argument_list|(
name|vp
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Global vfs data structures  */
end_comment

begin_comment
comment|/*  * NEEDSWORK: strategy,bmap are hand coded currently.  They should  * go away with a merged buffer/block cache.  *  */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
modifier|*
name|null_vnodeop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|vnodeopv_entry_desc
name|lofs_vnodeop_entries
index|[]
init|=
block|{
block|{
operator|&
name|vop_default_desc
block|,
name|null_bypass
block|}
block|,
block|{
operator|&
name|vop_getattr_desc
block|,
name|null_getattr
block|}
block|,
block|{
operator|&
name|vop_inactive_desc
block|,
name|null_inactive
block|}
block|,
block|{
operator|&
name|vop_reclaim_desc
block|,
name|null_reclaim
block|}
block|,
block|{
operator|&
name|vop_print_desc
block|,
name|null_print
block|}
block|,
block|{
operator|&
name|vop_bmap_desc
block|,
name|null_bmap
block|}
block|,
block|{
operator|&
name|vop_strategy_desc
block|,
name|null_strategy
block|}
block|,
block|{
operator|(
expr|struct
name|vnodeop_desc
operator|*
operator|)
name|NULL
block|,
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnodeopv_desc
name|lofs_vnodeop_opv_desc
init|=
block|{
operator|&
name|null_vnodeop_p
block|,
name|lofs_vnodeop_entries
block|}
decl_stmt|;
end_decl_stmt

end_unit

