begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_BEHAVIOR_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_BEHAVIOR_H__
end_define

begin_comment
comment|/*  * Header file used to associate behaviors with virtualized objects.  *  * A virtualized object is an internal, virtualized representation of  * OS entities such as persistent files, processes, or sockets.  Examples  * of virtualized objects include vnodes, vprocs, and vsockets.  Often  * a virtualized object is referred to simply as an "object."  *  * A behavior is essentially an implementation layer associated with  * an object.  Multiple behaviors for an object are chained together,  * the order of chaining determining the order of invocation.  Each  * behavior of a given object implements the same set of interfaces  * (e.g., the VOP interfaces).  *  * Behaviors may be dynamically inserted into an object's behavior chain,  * such that the addition is transparent to consumers that already have  * references to the object.  Typically, a given behavior will be inserted  * at a particular location in the behavior chain.  Insertion of new  * behaviors is synchronized with operations-in-progress (oip's) so that  * the oip's always see a consistent view of the chain.  *  * The term "interposition" is used to refer to the act of inserting  * a behavior such that it interposes on (i.e., is inserted in front  * of) a particular other behavior.  A key example of this is when a  * system implementing distributed single system image wishes to  * interpose a distribution layer (providing distributed coherency)  * in front of an object that is otherwise only accessed locally.  *  * Note that the traditional vnode/inode combination is simply a virtualized  * object that has exactly one associated behavior.  *  * Behavior synchronization is logic which is necessary under certain  * circumstances that there is no conflict between ongoing operations  * traversing the behavior chain and those dynamically modifying the  * behavior chain.  Because behavior synchronization adds extra overhead  * to virtual operation invocation, we want to restrict, as much as  * we can, the requirement for this extra code, to those situations  * in which it is truly necessary.  *  * Behavior synchronization is needed whenever there's at least one class  * of object in the system for which:  * 1) multiple behaviors for a given object are supported,  * -- AND --  * 2a) insertion of a new behavior can happen dynamically at any time during  *     the life of an active object,  *	-- AND --  *	3a) insertion of a new behavior needs to synchronize with existing  *	    ops-in-progress.  *	-- OR --  *	3b) multiple different behaviors can be dynamically inserted at  *	    any time during the life of an active object  *	-- OR --  *	3c) removal of a behavior can occur at any time during the life of  *	    an active object.  * -- OR --  * 2b) removal of a behavior can occur at any time during the life of an  *     active object  *  */
end_comment

begin_struct_decl
struct_decl|struct
name|bhv_head_lock
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Behavior head.  Head of the chain of behaviors.  * Contained within each virtualized object data structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bhv_head
block|{
name|struct
name|bhv_desc
modifier|*
name|bh_first
decl_stmt|;
comment|/* first behavior in chain */
name|struct
name|bhv_head_lock
modifier|*
name|bh_lockp
decl_stmt|;
comment|/* pointer to lock info struct */
block|}
name|bhv_head_t
typedef|;
end_typedef

begin_comment
comment|/*  * Behavior descriptor.	 Descriptor associated with each behavior.  * Contained within the behavior's private data structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bhv_desc
block|{
name|void
modifier|*
name|bd_pdata
decl_stmt|;
comment|/* private data for this behavior */
name|void
modifier|*
name|bd_vobj
decl_stmt|;
comment|/* virtual object associated with */
name|void
modifier|*
name|bd_ops
decl_stmt|;
comment|/* ops for this behavior */
name|struct
name|bhv_desc
modifier|*
name|bd_next
decl_stmt|;
comment|/* next behavior in chain */
block|}
name|bhv_desc_t
typedef|;
end_typedef

begin_comment
comment|/*  * Behavior identity field.  A behavior's identity determines the position  * where it lives within a behavior chain, and it's always the first field  * of the behavior's ops vector. The optional id field further identifies the  * subsystem responsible for the behavior.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bhv_identity
block|{
name|__u16
name|bi_id
decl_stmt|;
comment|/* owning subsystem id */
name|__u16
name|bi_position
decl_stmt|;
comment|/* position in chain */
block|}
name|bhv_identity_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bhv_identity_t
name|bhv_position_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BHV_IDENTITY_INIT
parameter_list|(
name|id
parameter_list|,
name|pos
parameter_list|)
value|{id, pos}
end_define

begin_define
define|#
directive|define
name|BHV_IDENTITY_INIT_POSITION
parameter_list|(
name|pos
parameter_list|)
value|BHV_IDENTITY_INIT(0, pos)
end_define

begin_comment
comment|/*  * Define boundaries of position values.  */
end_comment

begin_define
define|#
directive|define
name|BHV_POSITION_INVALID
value|0
end_define

begin_comment
comment|/* invalid position number */
end_comment

begin_define
define|#
directive|define
name|BHV_POSITION_BASE
value|1
end_define

begin_comment
comment|/* base (last) implementation layer */
end_comment

begin_define
define|#
directive|define
name|BHV_POSITION_TOP
value|63
end_define

begin_comment
comment|/* top (first) implementation layer */
end_comment

begin_comment
comment|/*  * Plumbing macros.  */
end_comment

begin_define
define|#
directive|define
name|BHV_HEAD_FIRST
parameter_list|(
name|bhp
parameter_list|)
value|(ASSERT((bhp)->bh_first), (bhp)->bh_first)
end_define

begin_define
define|#
directive|define
name|BHV_NEXT
parameter_list|(
name|bdp
parameter_list|)
value|(ASSERT((bdp)->bd_next), (bdp)->bd_next)
end_define

begin_define
define|#
directive|define
name|BHV_NEXTNULL
parameter_list|(
name|bdp
parameter_list|)
value|((bdp)->bd_next)
end_define

begin_define
define|#
directive|define
name|BHV_VOBJ
parameter_list|(
name|bdp
parameter_list|)
value|(ASSERT((bdp)->bd_vobj), (bdp)->bd_vobj)
end_define

begin_define
define|#
directive|define
name|BHV_VOBJNULL
parameter_list|(
name|bdp
parameter_list|)
value|((bdp)->bd_vobj)
end_define

begin_define
define|#
directive|define
name|BHV_PDATA
parameter_list|(
name|bdp
parameter_list|)
value|(bdp)->bd_pdata
end_define

begin_define
define|#
directive|define
name|BHV_OPS
parameter_list|(
name|bdp
parameter_list|)
value|(bdp)->bd_ops
end_define

begin_define
define|#
directive|define
name|BHV_IDENTITY
parameter_list|(
name|bdp
parameter_list|)
value|((bhv_identity_t *)(bdp)->bd_ops)
end_define

begin_define
define|#
directive|define
name|BHV_POSITION
parameter_list|(
name|bdp
parameter_list|)
value|(BHV_IDENTITY(bdp)->bi_position)
end_define

begin_function_decl
specifier|extern
name|void
name|bhv_head_init
parameter_list|(
name|bhv_head_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bhv_head_destroy
parameter_list|(
name|bhv_head_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bhv_insert
parameter_list|(
name|bhv_head_t
modifier|*
parameter_list|,
name|bhv_desc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bhv_insert_initial
parameter_list|(
name|bhv_head_t
modifier|*
parameter_list|,
name|bhv_desc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Initialize a new behavior descriptor.  * Arguments:  *   bdp - pointer to behavior descriptor  *   pdata - pointer to behavior's private data  *   vobj - pointer to associated virtual object  *   ops - pointer to ops for this behavior  */
end_comment

begin_define
define|#
directive|define
name|bhv_desc_init
parameter_list|(
name|bdp
parameter_list|,
name|pdata
parameter_list|,
name|vobj
parameter_list|,
name|ops
parameter_list|)
define|\
value|{							\ 	(bdp)->bd_pdata = pdata;			\ 	(bdp)->bd_vobj = vobj;				\ 	(bdp)->bd_ops = ops;				\ 	(bdp)->bd_next = NULL;				\  }
end_define

begin_comment
comment|/*  * Remove a behavior descriptor from a behavior chain.  */
end_comment

begin_define
define|#
directive|define
name|bhv_remove
parameter_list|(
name|bhp
parameter_list|,
name|bdp
parameter_list|)
define|\
value|{							\ 	if ((bhp)->bh_first == (bdp)) {			\
comment|/*					\ 		* Remove from front of chain.		\ 		* Atomic wrt oip's.			\ 		*/
value|\ 	       (bhp)->bh_first = (bdp)->bd_next;	\ 	} else {					\
comment|/* remove from non-front of chain */
value|\ 	       bhv_remove_not_first(bhp, bdp);		\ 	}						\ 	(bdp)->bd_vobj = NULL;				\  }
end_define

begin_comment
comment|/*  * Behavior module prototypes.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|bhv_remove_not_first
parameter_list|(
name|bhv_head_t
modifier|*
name|bhp
parameter_list|,
name|bhv_desc_t
modifier|*
name|bdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bhv_desc_t
modifier|*
name|bhv_lookup
parameter_list|(
name|bhv_head_t
modifier|*
name|bhp
parameter_list|,
name|void
modifier|*
name|ops
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bhv_desc_t
modifier|*
name|bhv_lookup_range
parameter_list|(
name|bhv_head_t
modifier|*
name|bhp
parameter_list|,
name|int
name|low
parameter_list|,
name|int
name|high
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bhv_desc_t
modifier|*
name|bhv_base
parameter_list|(
name|bhv_head_t
modifier|*
name|bhp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* No bhv locking on Linux */
end_comment

begin_define
define|#
directive|define
name|bhv_lookup_unlocked
value|bhv_lookup
end_define

begin_define
define|#
directive|define
name|bhv_base_unlocked
value|bhv_base
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_BEHAVIOR_H__ */
end_comment

end_unit

