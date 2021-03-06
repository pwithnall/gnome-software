/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2017 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __GS_FLATPAK_APP_H
#define __GS_FLATPAK_APP_H

#include <gnome-software.h>
#include <flatpak.h>

G_BEGIN_DECLS

#define GS_TYPE_FLATPAK_APP (gs_flatpak_app_get_type ())

G_DECLARE_FINAL_TYPE (GsFlatpakApp, gs_flatpak_app, GS, FLATPAK_APP, GsApp)

typedef enum {
	GS_FLATPAK_APP_FILE_KIND_UNKNOWN,
	GS_FLATPAK_APP_FILE_KIND_REPO,
	GS_FLATPAK_APP_FILE_KIND_REF,
	GS_FLATPAK_APP_FILE_KIND_BUNDLE,
	GS_FLATPAK_APP_FILE_KIND_LAST,
} GsFlatpakAppFileKind;

GsApp			*gs_flatpak_app_new			(const gchar	*id);

const gchar		*gs_flatpak_app_get_ref_name		(GsApp		*app);
const gchar		*gs_flatpak_app_get_ref_arch		(GsApp		*app);
const gchar		*gs_flatpak_app_get_ref_branch		(GsApp		*app);
FlatpakRefKind		 gs_flatpak_app_get_ref_kind		(GsApp		*app);
const gchar		*gs_flatpak_app_get_ref_kind_as_str	(GsApp		*app);
gchar			*gs_flatpak_app_get_ref_display		(GsApp		*app);

const gchar		*gs_flatpak_app_get_commit		(GsApp		*app);
const gchar		*gs_flatpak_app_get_object_id		(GsApp		*app);
const gchar		*gs_flatpak_app_get_repo_gpgkey		(GsApp		*app);
const gchar		*gs_flatpak_app_get_repo_url		(GsApp		*app);
GsFlatpakAppFileKind	 gs_flatpak_app_get_file_kind		(GsApp		*app);
GsApp			*gs_flatpak_app_get_runtime_repo	(GsApp		*app);

void			 gs_flatpak_app_set_ref_name		(GsApp		*app,
								 const gchar	*val);
void			 gs_flatpak_app_set_ref_arch		(GsApp		*app,
								 const gchar	*val);
void			 gs_flatpak_app_set_ref_branch		(GsApp		*app,
								 const gchar	*val);
void			 gs_flatpak_app_set_ref_kind		(GsApp		*app,
								 FlatpakRefKind	ref_kind);

void			 gs_flatpak_app_set_commit		(GsApp		*app,
								 const gchar	*val);
void			 gs_flatpak_app_set_object_id		(GsApp		*app,
								 const gchar	*val);
void			 gs_flatpak_app_set_repo_gpgkey		(GsApp		*app,
								 const gchar	*val);
void			 gs_flatpak_app_set_repo_url		(GsApp		*app,
								 const gchar	*val);
void			 gs_flatpak_app_set_file_kind		(GsApp		*app,
								 GsFlatpakAppFileKind	file_kind);
void			 gs_flatpak_app_set_runtime_repo	(GsApp		*app,
								 GsApp		*runtime_repo);

G_END_DECLS

#endif /* __GS_FLATPAK_APP_H */

/* vim: set noexpandtab: */
