<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->

<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Phunguy65/StudentManagementApp">
    <img src="assets/images/StudentManagementAppIcon.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">StudentManagementApp</h3>

  <p align="center">
    Ứng dụng quản lý sinh viên
    <br />
    <a href="https://github.com/Phunguy65/StudentManagementApp/"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Phunguy65/StudentManagementApp">Download App</a>
    ·
    <a href="https://github.com/github_username/repo_name/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    ·
    <a href="https://github.com/github_username/repo_name/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>&#128221; Tables of Contents</summary>
  <ol>
    <li>
      <a href="#monocle_face-about-the-project">About The Project</a>
      <ul>
        <li><a href="#hammer_and_wrench-built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#checkered_flag-getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#hourglass_flowing_sand-installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#dart-usage">Usage</a></li>
    <li><a href="#chart_with_upwards_trend-roadmap">Roadmap</a></li>
    <li><a href="#tada-contributing">Contributing</a></li>
    <li><a href="#page_with_curl-license">License</a></li>
    <li><a href="#email-contact">Contact</a></li>
    <li><a href="#pencil2-authors">Authors</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## :monocle_face: About The Project

[![Product Name Screen Shot][product-screenshot-01]](https://example.com)
[![Product Name Screen Shot][product-screenshot-02]](https://example.com)

StudentManagementApp là ứng dụng quản lý sinh viên được xây dựng dựa trên framework ***Qt*** và ngôn ngữ lập trình ***C++***.
Đây là một ứng dụng được phát triển theo yêu cầu của đồ án môn học **Cấu trúc dữ liệu và giải thuật** tại trường **Học viện Công nghệ Bưu chính Viễn thông - Thành phố Hồ Chí Minh**.

> :bulb: **Ưu điểm**:
>
> * Ứng dụng có giao diện thân thiện, dễ sử dụng
> * Bổ sung thêm các tính năng ngoài các yêu cầu cơ bản
>
> :warning: **Nhược điểm**:
>
> * Ứng dụng chỉ thiết kế `đơn luồng`, không hỗ trợ `đa luồng`, `bất đồng bộ`, điều này có thể gây ra hiện tượng `treo ứng dụng` khi xử lý dữ liệu lớn
> * Còn một số lỗi nhỏ có thể chưa được phát hiện

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### :hammer_and_wrench: Built With

* [![C++][cplusplus]][cplusplus-url]
* [![Qt][qt]][qt-url]
* [![CMake][cmake]][cmake-url]
* [![DSALibraries][dsalibraries]][dsalibraries-url] (Thư viện cấu trúc dữ liệu và giải thuật, do thành viên trong nhóm phát triển)
* [![Qxlsx][qxlsx]][qxlsx-url] (Thư viện hỗ trợ đọc và ghi file Excel, thanks to [@QtExcel](https://github.com/QtExcel)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->
## :checkered_flag: Getting Started

Để biết thêm thông tin về đồ án này, hãy xem [Docs](../docs).

Đây là ví dụ về cách cài đặt và sử dụng project **StudentManagementApp** trên máy tính của bạn. Để bắt đầu, hãy làm theo các bước sau đây.

### Prerequisites

Các điều kiện tiên quyết cần thiết để có thể dùng project này:

1. Cài đặt Qt 6.7.0

    1. Tạo tải khoản (nếu chưa có) tại [https://login.qt.io/login](https://login.qt.io/login)
    2. Tải Qt 6.7.0

      * Offline:
        * Windows:

          ```sh
          https://download.qt.io/official_releases/qt/6.7/6.7.0/single/qt-everywhere-src-6.7.0.zip
          ```

        * MacOS, Linux:

          ```sh
          https://download.qt.io/official_releases/qt/6.7/6.7.0/single/qt-everywhere-src-6.7.0.tar.xz
          ```

      * Online:

          * Windows:

            ```sh
            https://download.qt.io/official_releases/online_installers/qt-unified-windows-x64-online.exe
            ```

          * MacOS:

            ```sh
            https://download.qt.io/official_releases/online_installers/qt-unified-mac-x64-online.dmg
            ```

          * Linux:

            ```sh
            https://download.qt.io/official_releases/online_installers/qt-unified-linux-x64-online.run
            ```

          * Sau khi tải xong, chạy file cài đặt và chọn phiên bản cần cài đặt:
            1. Màn hình hiển thị `Qt Account` -> `Sign In` bằng tài khoản đã tạo
            2. Ấn `Next` để cho đến khi hiện màn hình `Add or remove components`
            3. Ấn `Next` để chọn phiên bản cần cài đặt
            4. `Tick` vào `Qt 6.7.0` và ấn `Next`
            5. Ấn `Install` để bắt đầu cài đặt
            6. Chờ đợi cho đến khi cài đặt xong, ấn `Finish`
          * Sau khi cài đặt hãy thêm biến môi trường (`Environment Variables`) cho Qt vào `PATH`, giá trị thêm vào là thư mục cài đặt Qt, ví dụ:

            ```sh
            C:\Qt\
            ```

2. Chọn IDE

    * Visual Studio 2019 (khuyến nghị chỉ dành cho Windows):

      ```sh
      https://visualstudio.microsoft.com/visual-cpp-build-tools
      ```

    * Qt Creator (khuyến nghị dành cho tất cả các hệ điều hành):

        ```sh
        https://download.qt.io/official_releases/qtcreator/latest
        ```

### :hourglass_flowing_sand: Installation

1. Tải project từ GitHub

   ```sh
   git clone https://github.com/Phunguy65/StudentManagementApp.git
   ```

2. Mở project bằng Qt Creator

    1. Mở Qt Creator
    2. Chọn `File` -> `Open File or Project...`
    3. Chọn file `CMakeLists.txt` trong thư mục project
    4. Chọn `Configure Project`

3. Build project

    1. Chọn `Build` -> `Build All`
    2. Chọn `Run` -> `Run`

4. Enjoy!

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## :dart: Usage

Hiện tại, tài liệu hướng dẫn sử dụng chỉ dành cho những người dùng cuối, vì vậy, tài liệu chỉ mô tả các tính năng của ứng dụng.

*Để biết thêm chi tiết, vui lòng xem tài liệu hướng dẫn tại [Docs](../docs)*

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ROADMAP -->
## :chart_with_upwards_trend: Roadmap

* [x] Giới thiệu về ứng dụng
  * [x] [Các tính năng](../docs/FeatureRequest.md)
* [ ] Sử dụng SQLite để lưu trữ dữ liệu

[open issues](https://github/Phunguy65/StudentManagementApp/issues) để xem thêm các tính năng được đề xuất (và các vấn đề đã biết).

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTRIBUTING -->
## :tada: Contributing

Những đóng góp chính là điều làm cho cộng đồng mã nguồn mở trở thành một nơi tuyệt vời để học hỏi, truyền cảm hứng và sáng tạo. Bất kỳ đóng góp nào của bạn đều **được đánh giá rất cao**.

Nếu bạn có đề xuất nào để làm cho dự án này tốt hơn, hãy fork repo và tạo một pull request. Bạn cũng có thể mở một issue với thẻ "enhancement".
Đừng quên gắn sao cho dự án! Cảm ơn bạn lần nữa!

1. Fork dự án
2. Tạo nhánh tính năng của bạn (`git checkout -b feature/AmazingFeature`)
3. Commit các thay đổi của bạn (`git commit -m 'Add some AmazingFeature'`)
4. Push lên nhánh (`git push origin feature/AmazingFeature`)
5. Mở một Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->
## :page_with_curl: License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
## :email: Contact

Nguyễn Ngọc Phú - <Ngocphunguyenabc@gmail.com>

Project Link: [https://github/Phunguy65/StudentManagementApp](https://github/Phunguy65/StudentManagementApp)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ACKNOWLEDGMENTS -->
## :pencil2: Authors

* [@Phunguy65](https://github/Phunguy65) - Nguyễn Ngọc Phú
* [@Anroyi](https://github/Anroyi) - Trần Hùng
* [@hnihTyoB](https://github/hnihTyoB) - Nguyễn Chí Thịnh
* [@tungbeoiotptithcm](https://github.com/tungbeoiotptithcm) - Nguyễn Thanh Tùng
* [@WhizKid](https://github.com/tuannguyen1229) - Nguyễn Như Tuấn

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/Phunguy65/StudentManagementApp.svg?style=for-the-badge
[contributors-url]: https://github.com/Phunguy65/StudentManagementApp/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Phunguy65/StudentManagementApp.svg?style=for-the-badge
[forks-url]: https://github.com/Phunguy65/StudentManagementApp/forks
[stars-shield]: https://img.shields.io/github/stars/Phunguy65/StudentManagementApp.svg?style=for-the-badge
[stars-url]: https://github.com/Phunguy65/StudentManagementApp/stargazers
[issues-shield]: https://img.shields.io/github/issues/Phunguy65/StudentManagementApp.svg?style=for-the-badge
[issues-url]: https://github.com/Phunguy65/StudentManagementApp/issues
[license-shield]: https://img.shields.io/github/license/Phunguy65/StudentManagementApp.svg?style=for-the-badge
[license-url]: https://github.com/Phunguy65/StudentManagementApp/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/ph%C3%BA-nguy%E1%BB%85n-ng%E1%BB%8Dc-82084a287/
[product-screenshot-01]: assets/images/OverviewTab.png
[product-screenshot-02]: assets/images/StatisticsTab.png
[cplusplus]: https://img.shields.io/badge/c++-23-00599C?style=flat&logo=cplusplus&logoColor=blue
[cplusplus-url]: https://isocpp.org/
[qt]: https://img.shields.io/badge/Qt-6.7.0-41CD52?style=flat&logo=qt&logoColor=#41CD52
[qt-url]: https://www.qt.io/
[cmake]: https://img.shields.io/badge/CMake-3.21.1-blue?style=flat&logo=cmake&logoColor=#064F8C
[cmake-url]: https://cmake.org/
[dsalibraries]: https://img.shields.io/badge/DSALibraries-1.0.0-FFA500?style=flat&logo=github&logoColor=FFA500
[dsalibraries-url]: https://github.com/Phunguy65/DSALibraries
[qxlsx]: https://img.shields.io/badge/QXlsx-1.4.8-FF0000?style=flat&logo=github&logoColor=FF0000
[qxlsx-url]: https://github.com/QtExcel/QXlsx
