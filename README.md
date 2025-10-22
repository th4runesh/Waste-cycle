# EcoWaste - Organic Waste Recycling Platform

A comprehensive platform connecting waste producers with recyclers, enabling carbon credit trading and building sustainable communities through AI-powered waste management.

## 🌱 Overview

EcoWaste is a full-stack Next.js application that revolutionizes organic waste management by:
- Connecting waste producers (farmers, households, hotels) with recyclers
- Using AI to classify and value organic waste
- Facilitating carbon credit trading through blockchain marketplace
- Building local communities around sustainability goals
- Providing comprehensive dashboards for all stakeholders

## 🚀 Quick Start

### Prerequisites

- Node.js 18+ 
- npm or yarn package manager
- Git

### Installation

1. **Clone the repository**
   \`\`\`bash
   git clone https://github.com/your-username/ecowaste-platform.git
   cd ecowaste-platform
   \`\`\`

2. **Install dependencies**
   \`\`\`bash
   npm install
   # or
   yarn install
   \`\`\`

3. **Set up environment variables**
   \`\`\`bash
   cp .env.example .env.local
   \`\`\`
   
   Configure the following variables in `.env.local`:
   \`\`\`env
   # Database
   DATABASE_URL="your_database_connection_string"
   
   # Authentication
   NEXTAUTH_SECRET="your_nextauth_secret"
   NEXTAUTH_URL="http://localhost:3000"
   
   # AI Services
   OPENAI_API_KEY="your_openai_api_key"
   
   # File Storage
   CLOUDINARY_CLOUD_NAME="your_cloudinary_name"
   CLOUDINARY_API_KEY="your_cloudinary_key"
   CLOUDINARY_API_SECRET="your_cloudinary_secret"
   
   # Blockchain (for carbon credits)
   ETHEREUM_RPC_URL="your_ethereum_rpc_url"
   PRIVATE_KEY="your_wallet_private_key"
   \`\`\`

4. **Run the development server**
   \`\`\`bash
   npm run dev
   # or
   yarn dev
   \`\`\`

5. **Open your browser**
   Navigate to [http://localhost:3000](http://localhost:3000)

## 📁 Project Structure

\`\`\`
ecowaste-platform/
├── app/                          # Next.js App Router
│   ├── page.jsx                  # Landing page
│   ├── layout.jsx                # Root layout
│   ├── globals.css               # Global styles
│   ├── auth/                     # Authentication
│   │   └── page.jsx              # Login/Register
│   ├── dashboard/                # User dashboards
│   │   ├── producer/page.jsx     # Producer dashboard
│   │   ├── recycler/page.jsx     # Recycler dashboard
│   │   └── corporate/page.jsx    # Corporate dashboard
│   ├── community/page.jsx        # Community hub
│   ├── marketplace/page.jsx      # Carbon credit marketplace
│   ├── admin/page.jsx            # Admin dashboard
│   └── profile/page.jsx          # User profile & settings
├── components/                   # Reusable UI components
│   └── ui/                       # shadcn/ui components
├── lib/                          # Utility functions
├── hooks/                        # Custom React hooks
└── docs/                         # Documentation
\`\`\`

## 🔧 Backend API Documentation

### Authentication Endpoints

#### POST `/api/auth/register`
Register a new user with role selection.

**Request Body:**
\`\`\`json
{
  "name": "John Doe",
  "email": "john@example.com",
  "password": "securepassword",
  "role": "producer|recycler|corporate",
  "location": "City, State",
  "phone": "+1234567890"
}
\`\`\`

**Response:**
\`\`\`json
{
  "success": true,
  "user": {
    "id": "user_id",
    "name": "John Doe",
    "email": "john@example.com",
    "role": "producer"
  },
  "token": "jwt_token"
}
\`\`\`

#### POST `/api/auth/login`
Authenticate user and return JWT token.

**Request Body:**
\`\`\`json
{
  "email": "john@example.com",
  "password": "securepassword"
}
\`\`\`

### Producer Dashboard APIs

#### POST `/api/waste/upload`
Upload waste photo and metadata for AI analysis.

**Request Body (multipart/form-data):**
\`\`\`
photo: File
weight: number
location: string
notes: string (optional)
\`\`\`

**Response:**
\`\`\`json
{
  "success": true,
  "analysis": {
    "type": "Vegetable Scraps",
    "confidence": 94,
    "estimatedValue": 12.50,
    "suggestions": ["High organic content", "Suitable for composting"]
  },
  "recyclerOffers": [
    {
      "id": "recycler_id",
      "name": "GreenTech Recyclers",
      "price": 5.00,
      "pickup": "Same Day",
      "rating": 4.8
    }
  ]
}
\`\`\`

#### GET `/api/producer/submissions`
Get producer's waste submission history.

**Response:**
\`\`\`json
{
  "submissions": [
    {
      "id": "submission_id",
      "date": "2024-01-15",
      "type": "Vegetable Scraps",
      "weight": 2.5,
      "status": "Completed",
      "earnings": 12.50,
      "recycler": "GreenTech Recyclers"
    }
  ],
  "totalEarnings": 284.50,
  "carbonCredits": 45.2
}
\`\`\`

### Recycler Dashboard APIs

#### GET `/api/recycler/available-waste`
Get available waste listings for recyclers.

**Query Parameters:**
- `location`: Filter by location radius
- `type`: Filter by waste type
- `minWeight`: Minimum weight filter

**Response:**
\`\`\`json
{
  "listings": [
    {
      "id": "waste_id",
      "producer": "Green Farm Co.",
      "location": "Downtown, 2.5km",
      "type": "Vegetable Scraps",
      "weight": 15.2,
      "price": 76.00,
      "posted": "2024-01-15T10:30:00Z"
    }
  ]
}
\`\`\`

#### POST `/api/recycler/accept-order`
Accept a waste collection order.

**Request Body:**
\`\`\`json
{
  "wasteId": "waste_id",
  "pickupDate": "2024-01-16",
  "notes": "Will pickup in the morning"
}
\`\`\`

#### POST `/api/recycler/process-waste`
Log waste processing and generate carbon credits.

**Request Body:**
\`\`\`json
{
  "orderId": "order_id",
  "processedWeight": 14.8,
  "processType": "composting|biogas|bioplastic",
  "outputProducts": ["compost", "biogas"],
  "carbonCreditsGenerated": 5.2
}
\`\`\`

### Corporate Dashboard APIs

#### GET `/api/corporate/carbon-credits`
Get available carbon credits for purchase.

**Response:**
\`\`\`json
{
  "credits": [
    {
      "id": "credit_id",
      "recycler": "GreenTech Recyclers",
      "projectType": "Compost Production",
      "co2Offset": 2.5,
      "price": 12.50,
      "certification": "Gold Standard",
      "available": true
    }
  ]
}
\`\`\`

#### POST `/api/corporate/purchase-credits`
Purchase carbon credits.

**Request Body:**
\`\`\`json
{
  "creditIds": ["credit_id_1", "credit_id_2"],
  "totalAmount": 50.00,
  "paymentMethod": "card|bank_transfer"
}
\`\`\`

### Community Hub APIs

#### GET `/api/community/local`
Get local communities based on user location.

**Response:**
\`\`\`json
{
  "communities": [
    {
      "id": "community_id",
      "name": "Green Warriors Community",
      "area": "Downtown District",
      "members": 1250,
      "co2Saved": 2.5,
      "description": "Leading urban waste recycling"
    }
  ]
}
\`\`\`

#### POST `/api/community/join`
Join a local community.

**Request Body:**
\`\`\`json
{
  "communityId": "community_id"
}
\`\`\`

#### POST `/api/community/contribute`
Log waste contribution to community.

**Request Body:**
\`\`\`json
{
  "communityId": "community_id",
  "wasteType": "Kitchen scraps",
  "weight": 2.5,
  "photo": "base64_image_data",
  "notes": "Weekly contribution"
}
\`\`\`

### Carbon Credit Marketplace APIs

#### GET `/api/marketplace/credits`
Browse available carbon credits.

**Query Parameters:**
- `type`: Filter by project type
- `priceRange`: Price range filter
- `certification`: Filter by certification type

**Response:**
\`\`\`json
{
  "credits": [
    {
      "id": "credit_id",
      "recyclerName": "GreenTech Recyclers",
      "projectType": "Compost Production",
      "co2Offset": 2.5,
      "price": 12.50,
      "pricePerTon": 5.00,
      "availability": "Available",
      "certification": "Gold Standard",
      "totalCredits": 500,
      "soldCredits": 125
    }
  ]
}
\`\`\`

### Admin Dashboard APIs

#### GET `/api/admin/users`
Get all platform users with filtering.

**Query Parameters:**
- `role`: Filter by user role
- `status`: Filter by account status
- `page`: Pagination

**Response:**
\`\`\`json
{
  "users": [
    {
      "id": "user_id",
      "name": "John Doe",
      "email": "john@example.com",
      "role": "producer",
      "status": "active",
      "joinDate": "2024-01-01",
      "totalContributions": 125.5
    }
  ],
  "totalUsers": 1250,
  "pagination": {
    "page": 1,
    "totalPages": 25
  }
}
\`\`\`

#### POST `/api/admin/approve-credits`
Approve carbon credit issuance requests.

**Request Body:**
\`\`\`json
{
  "requestId": "request_id",
  "approved": true,
  "notes": "Verification completed"
}
\`\`\`

#### GET `/api/admin/platform-stats`
Get platform-wide statistics.

**Response:**
\`\`\`json
{
  "stats": {
    "totalUsers": 1250,
    "totalWasteProcessed": 15420.5,
    "carbonCreditsIssued": 2840.2,
    "totalTransactions": 5680,
    "monthlyGrowth": 15.2
  }
}
\`\`\`

### Profile & Settings APIs

#### GET `/api/profile`
Get user profile information.

#### PUT `/api/profile`
Update user profile.

**Request Body:**
\`\`\`json
{
  "name": "Updated Name",
  "phone": "+1234567890",
  "location": "New City, State",
  "bio": "Updated bio",
  "notifications": {
    "email": true,
    "push": false,
    "sms": true
  }
}
\`\`\`

#### POST `/api/profile/change-password`
Change user password.

**Request Body:**
\`\`\`json
{
  "currentPassword": "current_password",
  "newPassword": "new_password"
}
\`\`\`

#### GET `/api/profile/transactions`
Get user transaction history.

**Response:**
\`\`\`json
{
  "transactions": [
    {
      "id": "txn_id",
      "type": "waste_sale|credit_purchase|community_reward",
      "amount": 25.00,
      "date": "2024-01-15",
      "status": "completed",
      "description": "Vegetable scraps sale"
    }
  ]
}
\`\`\`

## 🎨 Features by Page

### Landing Page (`/`)
- Dynamic hero section with rotating text
- Platform statistics display
- Feature showcase with animations
- Community highlights
- Carbon credit marketplace preview
- Navigation dropdown to all pages

### Authentication (`/auth`)
- Role-based registration (Producer/Recycler/Corporate)
- Login with JWT authentication
- Role-specific onboarding information
- Password reset functionality

### Producer Dashboard (`/dashboard/producer`)
- AI-powered waste photo analysis
- Waste weight estimation
- Recycler matching and offers
- Earnings tracking and history
- Carbon credits earned
- Environmental impact metrics

### Recycler Dashboard (`/dashboard/recycler`)
- Available waste listings with filters
- Order management system
- Processing logs and tracking
- Carbon credit generation
- Performance analytics
- Revenue tracking

### Corporate Dashboard (`/dashboard/corporate`)
- Carbon credit marketplace browsing
- ESG reporting and metrics
- Sustainability goal tracking
- Purchase history
- Impact measurement
- Portfolio management

### Community Hub (`/community`)
- Local community discovery
- Member leaderboards
- Activity feeds and contributions
- Waste logging and tracking
- Community challenges
- Social features

### Carbon Credit Marketplace (`/marketplace`)
- Credit browsing with advanced filters
- Purchase functionality
- Transaction history
- Impact tracking
- Verification status
- Price analytics

### Admin Dashboard (`/admin`)
- User management and oversight
- Carbon credit approval workflow
- Platform statistics and analytics
- Fraud detection and alerts
- System configuration
- Reporting tools

### Profile & Settings (`/profile`)
- Personal information management
- Security settings
- Notification preferences
- Transaction history
- Language settings
- Account management

## 🛠 Technology Stack

- **Frontend**: Next.js 14, React, TypeScript
- **Styling**: Tailwind CSS, shadcn/ui components
- **Authentication**: NextAuth.js
- **Database**: PostgreSQL with Prisma ORM
- **AI/ML**: OpenAI GPT-4 for waste classification
- **File Storage**: Cloudinary
- **Blockchain**: Ethereum for carbon credits
- **Deployment**: Vercel

## 🌍 Environment Variables

Create a `.env.local` file with the following variables:

\`\`\`env
# Database
DATABASE_URL="postgresql://username:password@localhost:5432/ecowaste"

# Authentication
NEXTAUTH_SECRET="your-secret-key"
NEXTAUTH_URL="http://localhost:3000"

# AI Services
OPENAI_API_KEY="sk-your-openai-key"

# File Storage
CLOUDINARY_CLOUD_NAME="your-cloud-name"
CLOUDINARY_API_KEY="your-api-key"
CLOUDINARY_API_SECRET="your-api-secret"

# Blockchain
ETHEREUM_RPC_URL="https://mainnet.infura.io/v3/your-project-id"
PRIVATE_KEY="your-wallet-private-key"

# Email Service
SMTP_HOST="smtp.gmail.com"
SMTP_PORT="587"
SMTP_USER="your-email@gmail.com"
SMTP_PASS="your-app-password"
\`\`\`

## 📱 Demo Credentials

For testing purposes, use these demo credentials:

**Producer Account:**
- Email: `producer@demo.com`
- Password: `demo123`

**Recycler Account:**
- Email: `recycler@demo.com`
- Password: `demo123`

**Corporate Account:**
- Email: `corporate@demo.com`
- Password: `demo123`

**Admin Account:**
- Email: `admin@demo.com`
- Password: `admin123`

## 🚀 Deployment

### Deploy to Vercel

1. Push your code to GitHub
2. Connect your repository to Vercel
3. Configure environment variables in Vercel dashboard
4. Deploy automatically on push to main branch

### Database Setup

1. Set up PostgreSQL database (recommended: Supabase or Neon)
2. Run database migrations:
   \`\`\`bash
   npx prisma migrate deploy
   \`\`\`
3. Seed initial data:
   \`\`\`bash
   npx prisma db seed
   \`\`\`

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/amazing-feature`
3. Commit your changes: `git commit -m 'Add amazing feature'`
4. Push to the branch: `git push origin feature/amazing-feature`
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 📞 Support

For support and questions:
- Email: help@ecowaste.com
- Phone: +91 7081312283
- Documentation: [docs.ecowaste.com](https://docs.ecowaste.com)

## 🙏 Acknowledgments

- OpenAI for AI-powered waste classification
- Vercel for hosting and deployment
- shadcn/ui for beautiful UI components
- The open-source community for amazing tools and libraries

---

**Built with ❤️ for a sustainable future** 🌱
