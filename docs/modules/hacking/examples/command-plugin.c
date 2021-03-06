#include "common.h"
#include "bio.h"
#include "bu.h"
#include "ged.h"

HIDDEN int
zoom(struct ged *gedp, double sf)
{
    gedp->ged_gvp->gv_scale /= sf;
    if (gedp->ged_gvp->gv_scale < RT_MINVIEWSCALE)
        gedp->ged_gvp->gv_scale = RT_MINVIEWSCALE;
    gedp->ged_gvp->gv_size = 2.0 * gedp->ged_gvp->gv_scale;
    gedp->ged_gvp->gv_isize = 1.0 / gedp->ged_gvp->gv_size;
    ged_view_update(gedp->ged_gvp);

    return GED_OK;
}

int
ged_zoom(struct ged *gedp, int argc, const char *argv[])
{
    int ret;
    double sf = 1.0;

    GED_CHECK_VIEW(gedp, GED_ERROR);
    GED_CHECK_ARGC_GT_0(gedp, argc, GED_ERROR);

    /* must be wanting help */
    if (argc != 2) {
        bu_vls_printf(gedp->ged_result_str, "Usage: %s scale_factor", argv[0]);
        return (argc == 1) ? GED_HELP : GED_ERROR;
    }

    /* get the scale factor */
    ret = bu_sscanf(argv[1], "%lf", &sf);
    if (ret != 1 || sf < SMALL_FASTF || sf > INFINITY) {
        bu_vls_printf(gedp->ged_result_str, "ERROR: bad scale factor [%s]", argv[1]);
        return GED_ERROR;
    }

    return zoom(gedp, sf);
}
