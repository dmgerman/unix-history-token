begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for file attribute munging features.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILEATTR_H
end_ifndef

begin_comment
comment|/* File containing per-file attributes.  The format of this file is in    cvs.texinfo but here is a quick summary.  The file contains a    series of entries:     ENT-TYPE FILENAME<tab> ATTRNAME = ATTRVAL      {; ATTRNAME = ATTRVAL}<linefeed>     ENT-TYPE is 'F' for a file.     ENT-TYPE is 'D', and FILENAME empty, for default attributes.     Other ENT-TYPE are reserved for future expansion.     Note that the order of the line is not significant; CVS is free to    rearrange them at its convenience.     FIXME: this implementation doesn't handle '\0' in any of the    fields.  We are encouraged to fix this (by cvs.texinfo).     By convention, ATTRNAME starting with '_' is for an attribute given    special meaning by CVS; other ATTRNAMEs are for user-defined attributes    (or will be, once we add commands to manipulate user-defined attributes).     Builtin attributes:     _watched: Present means the file is watched and should be checked out    read-only.     _watchers: Users with watches for this file.  Value is    WATCHER> TYPE { , WATCHER> TYPE }    where WATCHER is a username, and TYPE is edit,unedit,commit separated by    + (or nothing if none; there is no "none" or "all" keyword).     _editors: Users editing this file.  Value is    EDITOR> VAL { , EDITOR> VAL }    where EDITOR is a username, and VAL is TIME+HOSTNAME+PATHNAME, where    TIME is when the "cvs edit" command happened,    and HOSTNAME and PATHNAME are for the working directory.  */
end_comment

begin_define
define|#
directive|define
name|CVSREP_FILEATTR
value|"CVS/fileattr"
end_define

begin_escape
end_escape

begin_comment
comment|/* Prepare for a new directory with repository REPOS.  If REPOS is NULL,    then prepare for a "non-directory"; the caller can call fileattr_write    and fileattr_free, but must not call fileattr_get or fileattr_set.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|fileattr_startdir
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|repos
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the attribute ATTRNAME for file FILENAME.  The return value    points into memory managed by the fileattr_* routines, should not    be altered by the caller, and is only good until the next call to    fileattr_clear or fileattr_set.  It points to the value, terminated    by '\0' or ';'.  Return NULL if said file lacks said attribute.    If FILENAME is NULL, return default attributes (attributes for    files created in the future).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fileattr_get
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|filename
operator|,
specifier|const
name|char
operator|*
name|attrname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Like fileattr_get, but return a pointer to a newly malloc'd string    terminated by '\0' (or NULL if said file lacks said attribute).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fileattr_get0
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|filename
operator|,
specifier|const
name|char
operator|*
name|attrname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is just a string manipulation function; it does not manipulate    file attributes as such.       LIST is in the format     ATTRNAME NAMEVALSEP ATTRVAL {ENTSEP ATTRNAME NAMEVALSEP ATTRVAL}     And we want to put in an attribute with name NAME and value VAL,    replacing the already-present attribute with name NAME if there is    one.  Or if VAL is NULL remove attribute NAME.  Return a new    malloc'd list; don't muck with the one passed in.  If we are removing    the last attribute return NULL.  LIST can be NULL to mean that we    started out without any attributes.     Examples:     fileattr_modify ("abc=def", "xxx", "val", '=', ';')) => "abc=def;xxx=val"    fileattr_modify ("abc=def", "abc", "val", '=', ';')) => "abc=val"    fileattr_modify ("abc=v1;def=v2", "abc", "val", '=', ';'))      => "abc=val;def=v2"    fileattr_modify ("abc=v1;def=v2", "def", "val", '=', ';'))      => "abc=v1;def=val"    fileattr_modify ("abc=v1;def=v2", "xxx", "val", '=', ';'))      => "abc=v1;def=v2;xxx=val"    fileattr_modify ("abc=v1;def=v2;ghi=v3", "def", "val", '=', ';'))      => "abc=v1;def=val;ghi=v3" */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fileattr_modify
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|list
operator|,
specifier|const
name|char
operator|*
name|attrname
operator|,
specifier|const
name|char
operator|*
name|attrval
operator|,
name|int
name|namevalsep
operator|,
name|int
name|entsep
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set attribute ATTRNAME for file FILENAME to ATTRVAL.  If ATTRVAL is NULL,    the attribute is removed.  Changes are not written to disk until the    next call to fileattr_write.  If FILENAME is NULL, set attributes for    files created in the future.  If ATTRVAL is NULL, remove that attribute.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|fileattr_set
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|filename
operator|,
specifier|const
name|char
operator|*
name|attrname
operator|,
specifier|const
name|char
operator|*
name|attrval
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get all the attributes for file FILENAME.  They are returned as malloc'd    data in an unspecified format which is guaranteed only to be good for    passing to fileattr_setall, or NULL if no attributes.  If FILENAME is    NULL, get default attributes.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fileattr_getall
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the attributes for file FILENAME to ATTRS, overwriting all previous    attributes for that file.  ATTRS was obtained from a previous call to    fileattr_getall (malloc'd data or NULL).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|fileattr_setall
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|filename
operator|,
specifier|const
name|char
operator|*
name|attrs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the attributes for file FILENAME in whatever manner is appropriate    for a newly created file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|fileattr_newfile
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write out all modified attributes.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|fileattr_write
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free all memory allocated by fileattr_*.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|fileattr_free
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FILEATTR_H
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* fileattr.h */
end_comment

end_unit

