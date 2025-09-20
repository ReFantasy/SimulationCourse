#include "tools/tobj_reader.h"

using namespace std;

namespace snow
{

    ///////////////////////////////////////////////////////////////////////
    // read in OBJ-style tet mesh file
    ///////////////////////////////////////////////////////////////////////
    bool readTobjFile(const string& filename, vector<VECTOR3>& vertices, vector<VECTOR4I>& tets)
    {
        // erase whatever was in the vectors before
        vertices.clear();
        tets.clear();

        FILE* file = fopen(filename.c_str(), "r");
        cout << " Reading in *.tobj file " << filename.c_str() << endl;

        if (file == NULL)
        {
            cout << " Failed to open file!" << endl;
            return false;
        }

        char nextChar = getc(file);

        // get the vertices
        while (nextChar == 'v' && nextChar != EOF)
        {
            ungetc(nextChar, file);

            double v[3];
            fscanf(file, "v %lf %lf %lf\n", &v[0], &v[1], &v[2]);
            vertices.push_back(VECTOR3(v[0], v[1], v[2]));

            nextChar = getc(file);
        }
        if (nextChar == EOF)
        {
            cout << " ERROR: File contains only vertices and no tets! " << endl;
            return false;
        }
        cout << " Found " << vertices.size() << " vertices " << endl;

        // get the tets
        while (nextChar == 't' && nextChar != EOF)
        {
            ungetc(nextChar, file);

            VECTOR4I tet;
            fscanf(file, "t %i %i %i %i\n", &tet[0], &tet[1], &tet[2], &tet[3]);
            tets.push_back(tet);

            nextChar = getc(file);
        }
        cout << " Found " << tets.size() << " tets " << endl;
        fclose(file);

        return true;
    }
} // namespace snow
