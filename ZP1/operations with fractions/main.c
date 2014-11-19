#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int citatel;
    int jmenovatel;
} zlomek;

zlomek secti_zlomky(zlomek zlomek1, zlomek zlomek2);
zlomek vynasob_zlomky(zlomek z1, zlomek z2);
zlomek odecti_zlomky(zlomek zlomek1, zlomek zlomek2);
zlomek vydel_zlomky(zlomek z1, zlomek z2);

int main()
{
    zlomek zlomek1, zlomek2;
    zlomek zlomekx, zlomeky, zlomekw,zlomekz;
    int citatel1, citatel2, jmenovatel1, jmenovatel2;

    printf("Zadejte prvni zlomek: ");
    scanf("%d/%d",&citatel1,&jmenovatel1);
    printf("Zadejte druhy zlomek: ");
    scanf("%d/%d",&citatel2,&jmenovatel2);

    if(jmenovatel1 == 0 || jmenovatel2 == 0)
    {
        printf("Nelze delit nulou.");
        return 0;
    }
    else
    {
        zlomek1.citatel = citatel1;
        zlomek1.jmenovatel = jmenovatel1;

        zlomek2.citatel = citatel2;
        zlomek2.jmenovatel = jmenovatel2;

        zlomekx = secti_zlomky(zlomek1,zlomek2);
        zlomeky = odecti_zlomky(zlomek1,zlomek2);
        zlomekw = vynasob_zlomky(zlomek1,zlomek2);
        zlomekz = vydel_zlomky(zlomek1,zlomek2);
        if(zlomekz.jmenovatel == 0)
        {
            printf("po souctu: %d/%d, po odecteni: %d/%d, po nasobeni: %d/%d a nelze delit nulou.",
               zlomekx.citatel,zlomekx.jmenovatel,zlomeky.citatel,zlomeky.jmenovatel
               ,zlomekw.citatel,zlomekw.jmenovatel);
        }
        else
        {
        printf("po souctu: %d/%d, po odecteni: %d/%d, po nasobeni: %d/%d a po deleni: %d/%d",
               zlomekx.citatel,zlomekx.jmenovatel,zlomeky.citatel,zlomeky.jmenovatel
               ,zlomekw.citatel,zlomekw.jmenovatel,zlomekz.citatel,zlomekz.jmenovatel);
        }
    }

}

zlomek secti_zlomky(zlomek zlomek1, zlomek zlomek2)
{
    int spol = zlomek1.jmenovatel*zlomek2.jmenovatel;
    zlomek vys_zlomek;
    int nas1, nas2;
    nas1 = zlomek1.citatel*zlomek2.jmenovatel;
    nas2 = zlomek2.citatel*zlomek1.jmenovatel;
    vys_zlomek.jmenovatel = spol;
    vys_zlomek.citatel=nas1+nas2;

    int spold = gcd(vys_zlomek.citatel,vys_zlomek.jmenovatel);

    vys_zlomek.citatel = vys_zlomek.citatel/spold;
    vys_zlomek.jmenovatel = vys_zlomek.jmenovatel/spold;
    return vys_zlomek;
}

zlomek vynasob_zlomky(zlomek z1, zlomek z2)
{
    zlomek vys_zlomek;
    vys_zlomek.citatel = z1.citatel*z2.citatel;
    vys_zlomek.jmenovatel = z2.jmenovatel*z1.jmenovatel;

    int spold = gcd(vys_zlomek.citatel,vys_zlomek.jmenovatel);

    vys_zlomek.citatel = vys_zlomek.citatel/spold;
    vys_zlomek.jmenovatel = vys_zlomek.jmenovatel/spold;

    if(vys_zlomek.citatel == 0)
        vys_zlomek.jmenovatel = 0;

    return vys_zlomek;
}

zlomek odecti_zlomky(zlomek zlomek1, zlomek zlomek2)
{
    int spol = zlomek1.jmenovatel*zlomek2.jmenovatel;
    zlomek vys_zlomek;
    int nas1, nas2;
    nas1 = zlomek1.citatel*zlomek2.jmenovatel;
    nas2 = zlomek2.citatel*zlomek1.jmenovatel;
    vys_zlomek.jmenovatel = spol;
    vys_zlomek.citatel=nas1-nas2;

    int spold = gcd(vys_zlomek.citatel,vys_zlomek.jmenovatel);

    vys_zlomek.citatel = vys_zlomek.citatel/spold;
    vys_zlomek.jmenovatel = vys_zlomek.jmenovatel/spold;

    return vys_zlomek;
}

zlomek vydel_zlomky(zlomek z1, zlomek z2)
{
    zlomek vys_zlomek;

    vys_zlomek.citatel = z1.jmenovatel*z2.citatel;
    vys_zlomek.jmenovatel = z1.citatel*z2.jmenovatel;

    int spold = gcd(vys_zlomek.citatel,vys_zlomek.jmenovatel);

    vys_zlomek.citatel = vys_zlomek.citatel/spold;
    vys_zlomek.jmenovatel = vys_zlomek.jmenovatel/spold;

    return vys_zlomek;
}

int gcd(int prvni, int druhe)
{
    int vetsi, mensi;

    for (vetsi = prvni, mensi = druhe ; mensi != 0; )
    {
        int zbytek;
        zbytek = vetsi % mensi;
        vetsi = mensi;
        mensi = zbytek;
    }
    return vetsi;
}
