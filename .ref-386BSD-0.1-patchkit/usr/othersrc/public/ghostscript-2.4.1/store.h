begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* store.h */
end_comment

begin_comment
comment|/* Assignment macros */
end_comment

begin_comment
comment|/*  * Macros for storing a ref.  We use macros for storing into objects,  * since the storage manager needs to be able to track stores for  * save/restore and also for global/local checking.  * We also use macros for other ref assignments, because (as it happens)  * Turbo C generates pretty awful code for doing this.  *  * There are three cases that we need to distinguish:  *	- Storing to a stack (no special action);  *	- Storing into a newly created object (set l_new);  *	- Storing into a slot of an existing object (check l_new in  *	    old value, set in new value).  * The macros are called  *<make/store><new_type><case>(place_to_store, new_value)  * where<case> is nothing for storing to the stack, _new for storing into  * a new object, and _old for storing into an existing object.  * (The _old macros also take a client name for tracing and debugging.)  *<new_type> and new_value are chosen from the following alternatives:  *	ref_assign		POINTER TO arbitrary ref  *	make_t		type (only for null and mark)  *	make_tv		type, value field name, value  *			  (only for scalars, which don't have attributes)  *	make_tav	type, attributes, value field name, value  *	make_tasv	type, attributes, size, value field name, value  * There are also specialized make_ macros for specific types:  *	make_int, make_real, make_bool, make_false, make_true,  *	make_mark, make_null, make_oper.  * Not all of the specialized make_ macros have _new and _old variants.  *  * For _tav and _tasv, we must store the value first, because sometimes  * it depends on the contents of the place being stored into.  */
end_comment

begin_comment
comment|/*  * Define the most efficient ref assignment macro for the platform.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__TURBOC__
end_ifdef

begin_comment
comment|/* Move the data in two 32-bit chunks, because */
end_comment

begin_comment
comment|/* otherwise the compiler calls SCOPY@. */
end_comment

begin_comment
comment|/* The cast to void is to discourage the compiler from */
end_comment

begin_comment
comment|/* wanting to deliver the value of the expression. */
end_comment

begin_define
define|#
directive|define
name|ref_assign
parameter_list|(
name|pto
parameter_list|,
name|pfrom
parameter_list|)
define|\
value|(void)((pto)->value = (pfrom)->value,\ 	       (pto)->tas = (pfrom)->tas)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Trust the compiler and hope for the best. */
end_comment

begin_comment
comment|/* The MIPS compiler doesn't like the cast to void. */
end_comment

begin_define
define|#
directive|define
name|ref_assign
parameter_list|(
name|pto
parameter_list|,
name|pfrom
parameter_list|)
define|\
value|(*(pto) = *(pfrom))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/******  ****** NOTE: the declarations of alloc_save_*_mask, alloc_save_change,  ****** and alloc_refs are duplicated from save.h.  ******/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|alloc_save_new_mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* l_new if in save, 0 if not */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|alloc_save_test_mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 if in save, -1 if not */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|alloc_save_change
argument_list|(
name|P2
argument_list|(
name|ref
operator|*
name|ptr
argument_list|,
specifier|const
name|char
operator|*
name|client_name
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ref_save
parameter_list|(
name|pto
parameter_list|,
name|cname
parameter_list|)
define|\
value|(void)((r_type_attrs(pto)& l_new) == alloc_save_test_mask ?\ 	 alloc_save_change(pto, cname) : 0)
end_define

begin_define
define|#
directive|define
name|ref_mark_new
parameter_list|(
name|pto
parameter_list|)
value|((pto)->tas.type_attrs |= alloc_save_new_mask)
end_define

begin_define
define|#
directive|define
name|ref_assign_new
parameter_list|(
name|pto
parameter_list|,
name|pfrom
parameter_list|)
define|\
value|(void)(ref_assign(pto,pfrom), ref_mark_new(pto))
end_define

begin_define
define|#
directive|define
name|ref_assign_old
parameter_list|(
name|pto
parameter_list|,
name|pfrom
parameter_list|,
name|cname
parameter_list|)
define|\
value|(ref_save(pto,cname), ref_assign_new(pto,pfrom))
end_define

begin_decl_stmt
specifier|extern
name|ref
modifier|*
name|alloc_refs
argument_list|(
name|P2
argument_list|(
argument|uint num_refs
argument_list|,
argument|const char *client_name
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|make_t
parameter_list|(
name|pref
parameter_list|,
name|newtype
parameter_list|)
value|r_set_type(pref, newtype)
end_define

begin_define
define|#
directive|define
name|make_t_new
parameter_list|(
name|pref
parameter_list|,
name|newtype
parameter_list|)
define|\
value|r_set_type_attrs(pref, newtype, alloc_save_new_mask)
end_define

begin_define
define|#
directive|define
name|make_t_old
parameter_list|(
name|pref
parameter_list|,
name|newtype
parameter_list|,
name|cname
parameter_list|)
define|\
value|(ref_save(pref,cname), make_t_new(pref,newtype))
end_define

begin_define
define|#
directive|define
name|make_tav
parameter_list|(
name|pref
parameter_list|,
name|newtype
parameter_list|,
name|newattrs
parameter_list|,
name|valfield
parameter_list|,
name|newvalue
parameter_list|)
define|\
value|((pref)->value.valfield = (newvalue),\    r_set_type_attrs(pref, newtype, newattrs))
end_define

begin_define
define|#
directive|define
name|make_tav_new
parameter_list|(
name|pref
parameter_list|,
name|t
parameter_list|,
name|a
parameter_list|,
name|vf
parameter_list|,
name|v
parameter_list|)
define|\
value|make_tav(pref,t,(a)|alloc_save_new_mask,vf,v)
end_define

begin_define
define|#
directive|define
name|make_tav_old
parameter_list|(
name|pref
parameter_list|,
name|t
parameter_list|,
name|a
parameter_list|,
name|vf
parameter_list|,
name|v
parameter_list|,
name|cname
parameter_list|)
define|\
value|(ref_save(pref,cname), make_tav_new(pref,t,a,vf,v))
end_define

begin_define
define|#
directive|define
name|make_tv
parameter_list|(
name|pref
parameter_list|,
name|newtype
parameter_list|,
name|valfield
parameter_list|,
name|newvalue
parameter_list|)
define|\
value|make_tav(pref,newtype,0,valfield,newvalue)
end_define

begin_define
define|#
directive|define
name|make_tv_new
parameter_list|(
name|pref
parameter_list|,
name|t
parameter_list|,
name|vf
parameter_list|,
name|v
parameter_list|)
value|make_tav_new(pref,t,0,vf,v)
end_define

begin_define
define|#
directive|define
name|make_tv_old
parameter_list|(
name|pref
parameter_list|,
name|t
parameter_list|,
name|vf
parameter_list|,
name|v
parameter_list|,
name|cname
parameter_list|)
value|make_tav_old(pref,t,0,vf,v,cname)
end_define

begin_define
define|#
directive|define
name|make_tasv
parameter_list|(
name|pref
parameter_list|,
name|newtype
parameter_list|,
name|newattrs
parameter_list|,
name|newsize
parameter_list|,
name|valfield
parameter_list|,
name|newvalue
parameter_list|)
define|\
value|(make_tav(pref,newtype,newattrs,valfield,newvalue),\    r_set_size(pref, newsize))
end_define

begin_define
define|#
directive|define
name|make_tasv_new
parameter_list|(
name|pref
parameter_list|,
name|t
parameter_list|,
name|a
parameter_list|,
name|s
parameter_list|,
name|vf
parameter_list|,
name|v
parameter_list|)
define|\
value|(make_tav_new(pref,t,a,vf,v), r_set_size(pref,s))
end_define

begin_define
define|#
directive|define
name|make_tasv_old
parameter_list|(
name|pref
parameter_list|,
name|t
parameter_list|,
name|a
parameter_list|,
name|s
parameter_list|,
name|vf
parameter_list|,
name|v
parameter_list|,
name|cname
parameter_list|)
define|\
value|(make_tav_old(pref,t,a,vf,v,cname), r_set_size(pref,s))
end_define

begin_comment
comment|/* Type-specific constructor macros */
end_comment

begin_define
define|#
directive|define
name|make_bool
parameter_list|(
name|pref
parameter_list|,
name|bval
parameter_list|)
value|make_tv(pref, t_boolean, index, bval)
end_define

begin_define
define|#
directive|define
name|make_false
parameter_list|(
name|pref
parameter_list|)
value|make_bool(pref, 0)
end_define

begin_define
define|#
directive|define
name|make_true
parameter_list|(
name|pref
parameter_list|)
value|make_bool(pref, 1)
end_define

begin_define
define|#
directive|define
name|make_int
parameter_list|(
name|pref
parameter_list|,
name|ival
parameter_list|)
value|make_tv(pref, t_integer, intval, ival)
end_define

begin_define
define|#
directive|define
name|make_int_new
parameter_list|(
name|pref
parameter_list|,
name|ival
parameter_list|)
value|make_tv_new(pref, t_integer, intval, ival)
end_define

begin_define
define|#
directive|define
name|make_mark
parameter_list|(
name|pref
parameter_list|)
value|make_t(pref, t_mark)
end_define

begin_define
define|#
directive|define
name|make_null
parameter_list|(
name|pref
parameter_list|)
value|make_t(pref, t_null)
end_define

begin_define
define|#
directive|define
name|make_null_new
parameter_list|(
name|pref
parameter_list|)
value|make_t_new(pref, t_null)
end_define

begin_define
define|#
directive|define
name|make_null_old
parameter_list|(
name|pref
parameter_list|,
name|cname
parameter_list|)
value|make_t_old(pref, t_null, cname)
end_define

begin_define
define|#
directive|define
name|make_oper
parameter_list|(
name|pref
parameter_list|,
name|opidx
parameter_list|,
name|proc
parameter_list|)
define|\
value|make_tasv(pref, t_operator, a_executable, opidx, opproc, proc)
end_define

begin_define
define|#
directive|define
name|make_real
parameter_list|(
name|pref
parameter_list|,
name|rval
parameter_list|)
value|make_tv(pref, t_real, realval, rval)
end_define

begin_define
define|#
directive|define
name|make_real_new
parameter_list|(
name|pref
parameter_list|,
name|rval
parameter_list|)
value|make_tv_new(pref, t_real, realval, rval)
end_define

end_unit

