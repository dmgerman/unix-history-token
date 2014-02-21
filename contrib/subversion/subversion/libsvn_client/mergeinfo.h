begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * mergeinfo.h : Client library-internal mergeinfo APIs.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_CLIENT_MERGEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_CLIENT_MERGEINFO_H
end_define

begin_include
include|#
directive|include
file|"svn_wc.h"
end_include

begin_include
include|#
directive|include
file|"svn_client.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_client_private.h"
end_include

begin_escape
end_escape

begin_comment
comment|/*** Data Structures ***/
end_comment

begin_comment
comment|/* Structure to store information about working copy paths that need special    consideration during a mergeinfo aware merge -- See the    'THE CHILDREN_WITH_MERGEINFO ARRAY' meta comment and the doc string for the    function get_mergeinfo_paths() in libsvn_client/merge.c. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|svn_client__merge_path_t
block|{
specifier|const
name|char
modifier|*
name|abspath
decl_stmt|;
comment|/* Absolute working copy path. */
name|svn_boolean_t
name|missing_child
decl_stmt|;
comment|/* ABSPATH has an immediate child which                                         is missing, but is not switched. */
name|svn_boolean_t
name|switched_child
decl_stmt|;
comment|/* ABSPATH has an immediate child which                                         is switched. */
name|svn_boolean_t
name|switched
decl_stmt|;
comment|/* ABSPATH is switched. */
name|svn_boolean_t
name|has_noninheritable
decl_stmt|;
comment|/* ABSPATH has svn:mergeinfo set on it                                         which includes non-inheritable                                         revision ranges. */
name|svn_boolean_t
name|absent
decl_stmt|;
comment|/* ABSPATH is absent from the WC,                                         probably due to authz                                         restrictions. */
name|svn_boolean_t
name|child_of_noninheritable
decl_stmt|;
comment|/* ABSPATH has no explicit mergeinfo                                             itself but is the child of a                                             path with noniheritable                                             mergeinfo. */
comment|/* The remaining ranges to be merged to ABSPATH.  When describing a forward      merge this rangelist adheres to the rules for rangelists described in      svn_mergeinfo.h.  However, when describing reverse merges this      rangelist can contain reverse merge ranges that are not sorted per      svn_sort_compare_ranges(), but rather are sorted such that the ranges      with the youngest start revisions come first.  In both the forward and      reverse merge cases the ranges should never overlap.  This rangelist      may be empty but should never be NULL unless ABSENT is true. */
name|svn_rangelist_t
modifier|*
name|remaining_ranges
decl_stmt|;
name|svn_mergeinfo_t
name|pre_merge_mergeinfo
decl_stmt|;
comment|/* Explicit or inherited mergeinfo                                            on ABSPATH prior to a merge.                                            May be NULL. */
name|svn_mergeinfo_t
name|implicit_mergeinfo
decl_stmt|;
comment|/* Implicit mergeinfo on ABSPATH                                            prior to a merge.  May be NULL. */
name|svn_boolean_t
name|inherited_mergeinfo
decl_stmt|;
comment|/* Whether PRE_MERGE_MERGEINFO was                                            explicit or inherited. */
name|svn_boolean_t
name|scheduled_for_deletion
decl_stmt|;
comment|/* ABSPATH is scheduled for                                            deletion. */
name|svn_boolean_t
name|immediate_child_dir
decl_stmt|;
comment|/* ABSPATH is an immediate child                                            directory of the merge target,                                            has no explicit mergeinfo prior                                            to the merge, and the operational                                            depth of the merge is                                            svn_depth_immediates. */
name|svn_boolean_t
name|record_mergeinfo
decl_stmt|;
comment|/* Mergeinfo needs to be recorded                                            on ABSPATH to describe the                                            merge. */
name|svn_boolean_t
name|record_noninheritable
decl_stmt|;
comment|/* Non-inheritable mergeinfo needs to                                            be recorded on ABSPATH to describe                                            the merge. Implies RECORD_MERGEINFO                                            is true. */
block|}
name|svn_client__merge_path_t
typedef|;
end_typedef

begin_comment
comment|/* Return a deep copy of the merge-path structure OLD, allocated in POOL. */
end_comment

begin_function_decl
name|svn_client__merge_path_t
modifier|*
name|svn_client__merge_path_dup
parameter_list|(
specifier|const
name|svn_client__merge_path_t
modifier|*
name|old
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a new merge path structure, allocated in POOL.  Initialize the  * 'abspath' member to a deep copy of ABSPATH and all other fields to zero  * bytes. */
end_comment

begin_function_decl
name|svn_client__merge_path_t
modifier|*
name|svn_client__merge_path_create
parameter_list|(
specifier|const
name|char
modifier|*
name|abspath
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/*** Functions ***/
end_comment

begin_comment
comment|/* Find explicit or inherited WC mergeinfo for LOCAL_ABSPATH, and return it    in *MERGEINFO (NULL if no mergeinfo is set).  Set *INHERITED to    whether the mergeinfo was inherited (TRUE or FALSE), if INHERITED is    non-null.     This function will search for inherited mergeinfo in the parents of    LOCAL_ABSPATH only if the base revision of LOCAL_ABSPATH falls within    the range of the parent's last committed revision to the parent's base    revision (inclusive) or is LOCAL_ABSPATH is a local addition.  If asking    for the inherited mergeinfo of an added path (i.e. one with no base    revision), that path may inherit mergeinfo from its nearest parent    with a base revision and explicit mergeinfo.     INHERIT indicates whether explicit, explicit or inherited, or only    inherited mergeinfo for LOCAL_ABSPATH is retrieved.     Don't look for inherited mergeinfo any higher than LIMIT_ABSPATH    (ignored if NULL) or beyond any switched path.     Set *WALKED_PATH to the path climbed from LOCAL_ABSPATH to find inherited    mergeinfo, or "" if none was found. (ignored if NULL).     If IGNORE_INVALID_MERGEINFO is true, then syntactically invalid explicit    mergeinfo on found on LOCAL_ABSPATH is ignored and *MERGEINFO is set to an    empty hash.  If IGNORE_INVALID_MERGEINFO is false, then syntactically    invalid explicit mergeinfo on found on LOCAL_ABSPATH results in a    SVN_ERR_MERGEINFO_PARSE_ERROR error.  Regardless of    IGNORE_INVALID_MERGEINFO, if LOCAL_ABSPATH inherits invalid mergeinfo,    then *MERGEINFO is always set to an empty hash and no parse error is    raised. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_client__get_wc_mergeinfo
parameter_list|(
name|svn_mergeinfo_t
modifier|*
name|mergeinfo
parameter_list|,
name|svn_boolean_t
modifier|*
name|inherited
parameter_list|,
name|svn_mergeinfo_inheritance_t
name|inherit
parameter_list|,
specifier|const
name|char
modifier|*
name|local_abspath
parameter_list|,
specifier|const
name|char
modifier|*
name|limit_abspath
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|walked_path
parameter_list|,
name|svn_boolean_t
name|ignore_invalid_mergeinfo
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If INCLUDE_DESCENDANTS is FALSE, behave exactly like    svn_client__get_wc_mergeinfo() except the mergeinfo for LOCAL_ABSPATH is    put in the mergeinfo catalog MERGEINFO_CAT, mapped from LOCAL_ABSPATH's    repository root-relative path.     If INCLUDE_DESCENDANTS is true, then any subtrees under LOCAL_ABSPATH with    explicit mergeinfo are also included in MERGEINFO_CAT and again the    keys are the repository root-relative paths of the subtrees.  If no    mergeinfo is found, then *MERGEINFO_CAT is set to NULL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_client__get_wc_mergeinfo_catalog
parameter_list|(
name|svn_mergeinfo_catalog_t
modifier|*
name|mergeinfo_cat
parameter_list|,
name|svn_boolean_t
modifier|*
name|inherited
parameter_list|,
name|svn_boolean_t
name|include_descendants
parameter_list|,
name|svn_mergeinfo_inheritance_t
name|inherit
parameter_list|,
specifier|const
name|char
modifier|*
name|local_abspath
parameter_list|,
specifier|const
name|char
modifier|*
name|limit_path
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|walked_path
parameter_list|,
name|svn_boolean_t
name|ignore_invalid_mergeinfo
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Obtain any mergeinfo for URL from the repository, and set    it in *TARGET_MERGEINFO.     INHERIT indicates whether explicit, explicit or inherited, or only    inherited mergeinfo for URL is obtained.     If URL does not exist at REV, SVN_ERR_FS_NOT_FOUND or    SVN_ERR_RA_DAV_REQUEST_FAILED is returned and *TARGET_MERGEINFO    is untouched.     If there is no mergeinfo available for URL, or if the server    doesn't support a mergeinfo capability and SQUELCH_INCAPABLE is    TRUE, set *TARGET_MERGEINFO to NULL. If the server doesn't support    a mergeinfo capability and SQUELCH_INCAPABLE is FALSE, return an    SVN_ERR_UNSUPPORTED_FEATURE error.     RA_SESSION is an open RA session to the repository in which URL lives;    it may be temporarily reparented by this function. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_client__get_repos_mergeinfo
parameter_list|(
name|svn_mergeinfo_t
modifier|*
name|target_mergeinfo
parameter_list|,
name|svn_ra_session_t
modifier|*
name|ra_session
parameter_list|,
specifier|const
name|char
modifier|*
name|url
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|,
name|svn_mergeinfo_inheritance_t
name|inherit
parameter_list|,
name|svn_boolean_t
name|squelch_incapable
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If INCLUDE_DESCENDANTS is FALSE, behave exactly like    svn_client__get_repos_mergeinfo() except the mergeinfo for URL    is put in the mergeinfo catalog MERGEINFO_CAT, with the key being    the repository root-relative path of URL.     If INCLUDE_DESCENDANTS is true, then any subtrees under URL    with explicit mergeinfo are also included in MERGEINFO_CAT.  The    keys for the subtree mergeinfo are the repository root-relative    paths of the subtrees.  If no mergeinfo is found, then    *TARGET_MERGEINFO_CAT is set to NULL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_client__get_repos_mergeinfo_catalog
parameter_list|(
name|svn_mergeinfo_catalog_t
modifier|*
name|mergeinfo_cat
parameter_list|,
name|svn_ra_session_t
modifier|*
name|ra_session
parameter_list|,
specifier|const
name|char
modifier|*
name|url
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|,
name|svn_mergeinfo_inheritance_t
name|inherit
parameter_list|,
name|svn_boolean_t
name|squelch_incapable
parameter_list|,
name|svn_boolean_t
name|include_descendants
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Retrieve the direct mergeinfo for the TARGET_WCPATH from the WC's    mergeinfo prop, or that inherited from its nearest ancestor if the    target has no info of its own.     If no mergeinfo can be obtained from the WC or REPOS_ONLY is TRUE,    get it from the repository.  If the repository is contacted for mergeinfo    and RA_SESSION does not point to TARGET_WCPATH's URL, then it is    temporarily reparented.  If RA_SESSION is NULL, then a temporary session    is opened as needed.     Store any mergeinfo obtained for TARGET_WCPATH in    *TARGET_MERGEINFO, if no mergeinfo is found *TARGET_MERGEINFO is    NULL.     Like svn_client__get_wc_mergeinfo(), this function considers no    inherited mergeinfo to be found in the WC when trying to crawl into    a parent path with a different working revision.     INHERIT indicates whether explicit, explicit or inherited, or only    inherited mergeinfo for TARGET_WCPATH is retrieved.     If FROM_REPOS is not NULL, then set *FROM_REPOS to true if    *TARGET_MERGEINFO is inherited and the repository was contacted to    obtain it.  Set *FROM_REPOS to false otherwise.     If TARGET_WCPATH inherited its mergeinfo from a working copy ancestor    or if it was obtained from the repository, set *INHERITED to TRUE, set it    to FALSE otherwise, if INHERITED is non-null. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_client__get_wc_or_repos_mergeinfo
parameter_list|(
name|svn_mergeinfo_t
modifier|*
name|target_mergeinfo
parameter_list|,
name|svn_boolean_t
modifier|*
name|inherited
parameter_list|,
name|svn_boolean_t
modifier|*
name|from_repos
parameter_list|,
name|svn_boolean_t
name|repos_only
parameter_list|,
name|svn_mergeinfo_inheritance_t
name|inherit
parameter_list|,
name|svn_ra_session_t
modifier|*
name|ra_session
parameter_list|,
specifier|const
name|char
modifier|*
name|target_wcpath
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If INCLUDE_DESCENDANTS is false then behaves exactly like    svn_client__get_wc_or_repos_mergeinfo() except the mergeinfo for    TARGET_WCPATH is put in the mergeinfo catalog    TARGET_MERGEINFO_CATALOG, mapped from TARGET_WCPATH's repository    root-relative path.     IGNORE_INVALID_MERGEINFO behaves as per the argument of the same    name to svn_client__get_wc_mergeinfo().  It is applicable only if    the mergeinfo for TARGET_WCPATH is obtained from the working copy.     If INCLUDE_DESCENDANTS is true, then any subtrees under    TARGET_WCPATH with explicit mergeinfo are also included in    TARGET_MERGEINFO_CATALOG and again the keys are the repository    root-relative paths of the subtrees.  If no mergeinfo is found,    then *TARGET_MERGEINFO_CAT is set to NULL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_client__get_wc_or_repos_mergeinfo_catalog
parameter_list|(
name|svn_mergeinfo_catalog_t
modifier|*
name|target_mergeinfo_catalog
parameter_list|,
name|svn_boolean_t
modifier|*
name|inherited
parameter_list|,
name|svn_boolean_t
modifier|*
name|from_repos
parameter_list|,
name|svn_boolean_t
name|include_descendants
parameter_list|,
name|svn_boolean_t
name|repos_only
parameter_list|,
name|svn_boolean_t
name|ignore_invalid_mergeinfo
parameter_list|,
name|svn_mergeinfo_inheritance_t
name|inherit
parameter_list|,
name|svn_ra_session_t
modifier|*
name|ra_session
parameter_list|,
specifier|const
name|char
modifier|*
name|target_wcpath
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set *MERGEINFO_P to a mergeinfo constructed solely from the    natural history of PATHREV.     If RANGE_YOUNGEST and RANGE_OLDEST are valid, use them as inclusive    bounds on the revision ranges of returned mergeinfo.  PATHREV->rev,    RANGE_YOUNGEST and RANGE_OLDEST are governed by the same rules as the    PEG_REVISION, START_REV, and END_REV parameters (respectively) of    svn_ra_get_location_segments().     If HAS_REV_ZERO_HISTORY is not NULL, then set *HAS_REV_ZERO_HISTORY to    TRUE if the natural history includes revision 0, else to FALSE.     RA_SESSION is an open RA session to the repository of PATHREV;    it may be temporarily reparented by this function. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_client__get_history_as_mergeinfo
parameter_list|(
name|svn_mergeinfo_t
modifier|*
name|mergeinfo_p
parameter_list|,
name|svn_boolean_t
modifier|*
name|has_rev_zero_history
parameter_list|,
specifier|const
name|svn_client__pathrev_t
modifier|*
name|pathrev
parameter_list|,
name|svn_revnum_t
name|range_youngest
parameter_list|,
name|svn_revnum_t
name|range_oldest
parameter_list|,
name|svn_ra_session_t
modifier|*
name|ra_session
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Parse any explicit mergeinfo on LOCAL_ABSPATH and store it in    *MERGEINFO.  If no record of any mergeinfo exists, set *MERGEINFO to NULL.    Does not acount for inherited mergeinfo. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_client__parse_mergeinfo
parameter_list|(
name|svn_mergeinfo_t
modifier|*
name|mergeinfo
parameter_list|,
name|svn_wc_context_t
modifier|*
name|wc_ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|local_abspath
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write MERGEINFO into the WC for LOCAL_ABSPATH.  If MERGEINFO is NULL,    remove any SVN_PROP_MERGEINFO for LOCAL_ABSPATH.  If MERGEINFO is empty,    record an empty property value (e.g. "").  If CTX->NOTIFY_FUNC2 is    not null call it with notification type svn_wc_notify_merge_record_info    if DO_NOTIFICATION is true.     Use WC_CTX to access the working copy, and SCRATCH_POOL for any temporary    allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_client__record_wc_mergeinfo
parameter_list|(
specifier|const
name|char
modifier|*
name|local_abspath
parameter_list|,
name|svn_mergeinfo_t
name|mergeinfo
parameter_list|,
name|svn_boolean_t
name|do_notification
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write mergeinfo into the WC.  *  * For each path in RESULT_CATALOG, set the SVN_PROP_MERGEINFO  * property to represent the given mergeinfo, or remove the property  * if the given mergeinfo is null, and notify the change.  Leave  * other paths unchanged.  RESULT_CATALOG maps (const char *) WC paths  * to (svn_mergeinfo_t) mergeinfo. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_client__record_wc_mergeinfo_catalog
parameter_list|(
name|apr_hash_t
modifier|*
name|result_catalog
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Elide any svn:mergeinfo set on TARGET_ABSPATH to its nearest working    copy (or possibly repository) ancestor with equivalent mergeinfo.     If WC_ELISION_LIMIT_ABSPATH is NULL check up to the root of the    working copy or the nearest switched parent for an elision    destination, if none is found check the repository, otherwise check    as far as WC_ELISION_LIMIT_ABSPATH within the working copy.    TARGET_WCPATH and WC_ELISION_LIMIT_ABSPATH, if it exists, must both be    absolute or relative to the working directory.     Elision occurs if:       A) TARGET_ABSPATH has empty mergeinfo and no parent path with         explicit mergeinfo can be found in either the WC or the         repository (WC_ELISION_LIMIT_PATH must be NULL for this to         occur).       B) TARGET_ABSPATH has empty mergeinfo and its nearest parent also         has empty mergeinfo.       C) TARGET_ABSPATH has the same mergeinfo as its nearest parent         when that parent's mergeinfo is adjusted for the path         difference between the two, e.g.:             TARGET_ABSPATH                = A_COPY/D/H            TARGET_ABSPATH's mergeinfo    = '/A/D/H:3'            TARGET_ABSPATH nearest parent = A_COPY            Parent's mergeinfo            = '/A:3'            Path difference               = 'D/H'            Parent's adjusted mergeinfo   = '/A/D/H:3'     If Elision occurs remove the svn:mergeinfo property from    TARGET_ABSPATH. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_client__elide_mergeinfo
parameter_list|(
specifier|const
name|char
modifier|*
name|target_abspath
parameter_list|,
specifier|const
name|char
modifier|*
name|wc_elision_limit_abspath
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Simplify a mergeinfo catalog, if possible, via elision.     For each path in MERGEINFO_CATALOG, check if the path's mergeinfo can    elide to the path's nearest path-wise parent in MERGEINFO_CATALOG.  If    so, remove that path from MERGEINFO_CATALOG.  Elidability is determined    as per svn_client__elide_mergeinfo except that elision to the repository    is not considered.     SCRATCH_POOL is used for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_client__elide_mergeinfo_catalog
parameter_list|(
name|svn_mergeinfo_catalog_t
name|mergeinfo_catalog
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set *MERGEINFO_CHANGES to TRUE if LOCAL_ABSPATH has locally modified    mergeinfo, set *MERGEINFO_CHANGES to FALSE otherwise. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_client__mergeinfo_status
parameter_list|(
name|svn_boolean_t
modifier|*
name|mergeinfo_changes
parameter_list|,
name|svn_wc_context_t
modifier|*
name|wc_ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|local_abspath
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_LIBSVN_CLIENT_MERGEINFO_H */
end_comment

end_unit

