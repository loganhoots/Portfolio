package com.example.presidentlist;

import android.app.Application;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MyApplication extends Application {
    private static List<President> presidentList = new ArrayList<President>();
    private static int nextID = 20;

    public MyApplication() {
        fillPresidentList();
    }

    private void fillPresidentList() {
        President p0 = new President(0, "George Washington", 1788, "https://upload.wikimedia.org/wikipedia/commons/thumb/b/b6/Gilbert_Stuart_Williamstown_Portrait_of_George_Washington.jpg/240px-Gilbert_Stuart_Williamstown_Portrait_of_George_Washington.jpg");
        President p1 = new President(1, "John Adams", 1796, "https://upload.wikimedia.org/wikipedia/commons/thumb/7/70/John_Adams%2C_Gilbert_Stuart%2C_c1800_1815.jpg/240px-John_Adams%2C_Gilbert_Stuart%2C_c1800_1815.jpg");
        President p2 = new President(2, "Thomas Jefferson", 1800, "https://upload.wikimedia.org/wikipedia/commons/thumb/1/1e/Thomas_Jefferson_by_Rembrandt_Peale%2C_1800.jpg/240px-Thomas_Jefferson_by_Rembrandt_Peale%2C_1800.jpg");
        President p3 = new President(3, "James Madison", 1808, "https://upload.wikimedia.org/wikipedia/commons/thumb/1/1d/James_Madison.jpg/240px-James_Madison.jpg");
        President p4 = new President(4, "James Monroe", 1816, "https://upload.wikimedia.org/wikipedia/commons/thumb/d/d4/James_Monroe_White_House_portrait_1819.jpg/240px-James_Monroe_White_House_portrait_1819.jpg");
        President p5 = new President(5, "John Quincy Adams", 1824, "https://upload.wikimedia.org/wikipedia/commons/thumb/5/51/JQA_Photo.tif/lossy-page1-240px-JQA_Photo.tif.jpg");
        President p6 = new President(6, "Andrew Jackson", 1828, "https://upload.wikimedia.org/wikipedia/commons/thumb/4/43/Andrew_jackson_head.jpg/248px-Andrew_jackson_head.jpg");
        President p7 = new President(7, "Martin Van Buren", 1836, "https://upload.wikimedia.org/wikipedia/commons/thumb/9/94/Martin_Van_Buren_edit.jpg/240px-Martin_Van_Buren_edit.jpg");
        President p8 = new President(8, "William Henry Harrison", 1840, "https://upload.wikimedia.org/wikipedia/commons/thumb/c/c5/William_Henry_Harrison_daguerreotype_edit.jpg/240px-William_Henry_Harrison_daguerreotype_edit.jpg");
        President p9 = new President(9, "John Tyler", 1840, "https://upload.wikimedia.org/wikipedia/commons/thumb/1/1d/John_Tyler%2C_Jr.jpg/240px-John_Tyler%2C_Jr.jpg");
        President p10 = new President(10, "James K. Polk", 1844, "https://upload.wikimedia.org/wikipedia/commons/thumb/5/5e/JKP.jpg/240px-JKP.jpg");
        President p11 = new President(11, "Zachary Taylor", 1848, "https://upload.wikimedia.org/wikipedia/commons/thumb/5/51/Zachary_Taylor_restored_and_cropped.jpg/240px-Zachary_Taylor_restored_and_cropped.jpg");
        President p12 = new President(12, "Millard Fillmore", 1848, "https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Fillmore.jpg/240px-Fillmore.jpg");
        President p13 = new President(13, "Franklin Pierce", 1852, "https://upload.wikimedia.org/wikipedia/commons/thumb/a/a7/Mathew_Brady_-_Franklin_Pierce_-_alternate_crop_%28cropped%29.jpg/240px-Mathew_Brady_-_Franklin_Pierce_-_alternate_crop_%28cropped%29.jpg");
        President p14 = new President(14, "James Buchanan", 1856, "https://upload.wikimedia.org/wikipedia/commons/thumb/f/fd/James_Buchanan.jpg/240px-James_Buchanan.jpg");
        President p15 = new President(15, "Abraham Lincoln", 1860, "https://upload.wikimedia.org/wikipedia/commons/thumb/a/ab/Abraham_Lincoln_O-77_matte_collodion_print.jpg/240px-Abraham_Lincoln_O-77_matte_collodion_print.jpg");
        President p16 = new President(16, "Andrew Johnson", 1864, "https://upload.wikimedia.org/wikipedia/commons/thumb/e/e6/Andrew_Johnson_photo_portrait_head_and_shoulders%2C_c1870-1880-Edit1.jpg/240px-Andrew_Johnson_photo_portrait_head_and_shoulders%2C_c1870-1880-Edit1.jpg");
        President p17 = new President(17, "Ulysses S. Grant", 1868, "https://upload.wikimedia.org/wikipedia/commons/thumb/7/75/Ulysses_S_Grant_by_Brady_c1870-restored.jpg/240px-Ulysses_S_Grant_by_Brady_c1870-restored.jpg");
        President p18 = new President(18, "Rutherford B. Hayes", 1876, "https://upload.wikimedia.org/wikipedia/commons/thumb/5/50/President_Rutherford_Hayes_1870_-_1880_Restored.jpg/240px-President_Rutherford_Hayes_1870_-_1880_Restored.jpg");
        President p19 = new President(19, "James A. Garfield", 1880, "https://upload.wikimedia.org/wikipedia/commons/thumb/1/1f/James_Abram_Garfield%2C_photo_portrait_seated.jpg/240px-James_Abram_Garfield%2C_photo_portrait_seated.jpg");

        presidentList.addAll(Arrays.asList(new President[] {p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19}));
    }

    public static List<President> getPresidentList() { return presidentList; }
    public static void setPresidentList(List<President> presidentList) { MyApplication.presidentList = presidentList; }
    public static int getNextID() { return nextID; }
    public static void setNextID(int nextID) { MyApplication.nextID = nextID; }
}