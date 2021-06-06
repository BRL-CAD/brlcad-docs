#include "common.h"
#include "raytrace.h"

/* basically this callback function counts how many CSG nodes are underneath
 * a given combination tree hierarchy.
 */
int
incr_region(struct db_tree_state *tsp, struct db_full_path *pathp, const struct rt_comb_internal *combp, void *data)
{
  int *counter = (int*)data;
  bu_log("...incrementing...\n");
  (*counter)++;
  return 0;
}

int
main(int argc, char *argv[])
{
  struct db_i *dbip;
  int counter = 0;
  struct db_tree_state state = rt_initial_tree_state;

  if (argc < 2) {
    bu_exit(0, "need more, db.g obj\n");
  }

  /* open a .g file for reading */
  dbip = db_open(argv[1], "r");
  if (dbip == NULL) {
    bu_exit(1, "Unable to open %s\n", argv[1]);
  }

  /* build a directory of objects */
  if (db_dirbuild(dbip) < 0) {
    db_close(dbip);
    bu_exit(1, "Unable to load %s\n", argv[1]);
  }

  bu_log("Database title is:\n%s\n", dbip->dbi_title);
  bu_log("Units: %s\n", bu_units_string(dbip->dbi_local2base));

  /* load a particular combination object */
  if (db_lookup(dbip, argv[2], 1) == NULL) {
    db_close(dbip);
    bu_exit(1, "Unable to find %s\n", argv[2]);
  }

  state.ts_dbip = dbip;
  state.ts_resp = &rt_uniresource;
  rt_init_resource( &rt_uniresource, 0, NULL );

  /* walk that combination object's hierarchy,
   * calling our incr_region() callback function.
   * we pass a pointer to our counter variable.
   */
  db_walk_tree(dbip, 1, (const char **)argv+2, 1, &state, incr_region, NULL, NULL, &counter);

  bu_log("counter is %d\n", counter);

  return 0;
}
