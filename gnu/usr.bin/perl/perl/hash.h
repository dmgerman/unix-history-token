begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $RCSfile: hash.h,v $$Revision: 1.2 $$Date: 1995/05/30 05:03:08 $  *  *    Copyright (c) 1991, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  * $Log: hash.h,v $  * Revision 1.2  1995/05/30 05:03:08  rgrimes  * Remove trailing whitespace.  *  * Revision 1.1.1.1  1994/09/10  06:27:35  gclarkii  * Initial import of Perl 4.046 bmaked  *  * Revision 1.1.1.1  1993/08/23  21:29:37  nate  * PERL!  *  * Revision 4.0.1.2  91/11/05  17:24:31  lwall  * patch11: random cleanup  *  * Revision 4.0.1.1  91/06/07  11:10:33  lwall  * patch4: new copyright notice  *  * Revision 4.0  91/03/20  01:22:38  lwall  * 4.0 baseline.  *  */
end_comment

begin_define
define|#
directive|define
name|FILLPCT
value|80
end_define

begin_comment
comment|/* don't make greater than 99 */
end_comment

begin_define
define|#
directive|define
name|DBM_CACHE_MAX
value|63
end_define

begin_comment
comment|/* cache 64 entries for dbm file */
end_comment

begin_comment
comment|/* (resident array acts as a write-thru cache)*/
end_comment

begin_define
define|#
directive|define
name|COEFFSIZE
value|(16 * 8)
end_define

begin_comment
comment|/* size of coeff array */
end_comment

begin_typedef
typedef|typedef
name|struct
name|hentry
name|HENT
typedef|;
end_typedef

begin_struct
struct|struct
name|hentry
block|{
name|HENT
modifier|*
name|hent_next
decl_stmt|;
name|char
modifier|*
name|hent_key
decl_stmt|;
name|STR
modifier|*
name|hent_val
decl_stmt|;
name|int
name|hent_hash
decl_stmt|;
name|int
name|hent_klen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|htbl
block|{
name|HENT
modifier|*
modifier|*
name|tbl_array
decl_stmt|;
name|int
name|tbl_max
decl_stmt|;
comment|/* subscript of last element of tbl_array */
name|int
name|tbl_dosplit
decl_stmt|;
comment|/* how full to get before splitting */
name|int
name|tbl_fill
decl_stmt|;
comment|/* how full tbl_array currently is */
name|int
name|tbl_riter
decl_stmt|;
comment|/* current root of iterator */
name|HENT
modifier|*
name|tbl_eiter
decl_stmt|;
comment|/* current entry of iterator */
name|SPAT
modifier|*
name|tbl_spatroot
decl_stmt|;
comment|/* list of spats for this package */
name|char
modifier|*
name|tbl_name
decl_stmt|;
comment|/* name, if a symbol table */
ifdef|#
directive|ifdef
name|SOME_DBM
ifdef|#
directive|ifdef
name|HAS_GDBM
name|GDBM_FILE
name|tbl_dbm
decl_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|HAS_NDBM
name|DBM
modifier|*
name|tbl_dbm
decl_stmt|;
else|#
directive|else
name|int
name|tbl_dbm
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
name|unsigned
name|char
name|tbl_coeffsize
decl_stmt|;
comment|/* is 0 for symbol tables */
block|}
struct|;
end_struct

begin_function_decl
name|STR
modifier|*
name|hfetch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|hstore
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|hdelete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|HASH
modifier|*
name|hnew
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hclear
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hentfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hiterinit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|HENT
modifier|*
name|hiternext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|hiterkey
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STR
modifier|*
name|hiterval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|hdbmopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hdbmclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|hdbmstore
parameter_list|()
function_decl|;
end_function_decl

end_unit

